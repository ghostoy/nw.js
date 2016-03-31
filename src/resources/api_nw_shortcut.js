var nw_binding = require('binding').Binding.create('nw.Shortcut');
var sendRequest = require('sendRequest');
var nwNatives = requireNative('nw_natives');
var EventEmitter = nw.require('events').EventEmitter;

var OPTION_INVALID = 'Invalid option.';
var OPTION_KEY_REQUIRED = "Shortcut requires 'key' to specify key combinations.";
var OPTION_KEY_INVALID = "Invalid 'key' format.";
var OPTION_ACTIVE_INVALID = "'active' must be a valid function.";
var OPTION_FAILED_INVALID = "'failed' must be a valid function.";
var ARUGMENT_NOT_SHORTCUT = "'shortcut' argument is not an instance of nw.Shortcut";
var UNABLE_REGISTER_HOTKEY = "Unable to register the hotkey";
var UNABLE_UNREGISTER_HOTKEY = "Unable to unregister the hotkey";

// Hook Sync API calls
nw_binding.registerCustomHook(function(bindingsAPI) {
  var apiFunctions = bindingsAPI.apiFunctions;
  ['registerAccelerator', 'unregisterAccelerator'].forEach(function(nwSyncAPIName) {
    apiFunctions.setHandleRequest(nwSyncAPIName, function() {
      return sendRequest.sendRequestSync(this.name, arguments, this.definition.parameters, {})[0];
    });
  });
});

var nwShortcutBinding = nw_binding.generate();
var handlers = {};

function keyToAccelerator(key) {
  return nwNatives.normalizeKeyString(key);
}

function normalizeLocal(accelerator) {
  return accelerator;
}

function getRegistryLocal(accelerator) {
  var localKey = normalizeLocal(accelerator);
  return handlers[localKey];
}

function registerLocal(shortcut) {
  var localKey = normalizeLocal(shortcut._accelerator);
  handlers[localKey] = shortcut;
}

function unregisterLocal(shortcut) {
  var localKey = normalizeLocal(shortcut._accelerator);
  delete handlers[localKey];
}

function Shortcut(option) {
  if (!(this instanceof Shortcut)) {
    return new Shortcut(option);
  }

  EventEmitter.apply(this, arguments);

  if (typeof option != 'object')
    throw new TypeError(OPTION_INVALID);

  if (!option.key)
    throw new TypeError(OPTION_KEY_REQUIRED);

  if (option.hasOwnProperty('active')) {
    if (typeof option.active != 'function')
      throw new TypeError(OPTION_ACTIVE_INVALID);
  }

  if (option.hasOwnProperty('failed')) {
    if (typeof option.failed != 'function')
      throw new TypeError(OPTION_FAILED_INVALID);
  }

  var self = this;

  this.on('active', function() {
    if (!self.active) return;
    if (typeof self.active != 'function')
      throw new TypeError(OPTION_ACTIVE_INVALID);
    self.active.apply(self, arguments);
  });

  this.on('failed', function() {
    if (!self.failed) return;
    if (typeof self.failed != 'function')
      throw new TypeError(OPTION_FAILED_INVALID);
    self.failed.apply(self, arguments);
  });

  this.key = option.key;
  this.active = option.active;
  this.failed = option.failed;

  this._accelerator = keyToAccelerator(option.key);
}

nw.require('util').inherits(Shortcut, EventEmitter);

Shortcut.registerGlobalHotKey = function(shortcut) {
  if (!(shortcut instanceof Shortcut)) {
    throw new TypeError(ARUGMENT_NOT_SHORTCUT);
  }

  if(nwShortcutBinding.registerAccelerator(shortcut._accelerator)) {
    registerLocal(shortcut);
  } else {
    shortcut.emit('failed', new Error(UNABLE_REGISTER_HOTKEY));
  }
};

Shortcut.unregisterGlobalHotKey = function(shortcut) {
  if (!(shortcut instanceof Shortcut)) {
    throw new TypeError(ARUGMENT_NOT_SHORTCUT);
  }

  var handler = getRegistryLocal(shortcut._accelerator);
  if(handler && nwShortcutBinding.unregisterAccelerator(shortcut._accelerator)) {
    unregisterLocal(shortcut);
  } else {
    shortcut.emit('failed', new Error(UNABLE_UNREGISTER_HOTKEY));
  }
};

nwShortcutBinding.onKeyPressed.addListener(function(accelerator) {
  var handler = getRegistryLocal(accelerator);
  if (handler) {
    handler.emit('active');
  }
});

exports.binding = Shortcut;