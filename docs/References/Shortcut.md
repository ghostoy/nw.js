# Shortcut {: .doctitle}

---

[TOC]

`Shortcut` represents a global keyboard shortcut, also known as system-wide hotkey. If registered successfully, it works even if your app does *not* have focus.

`Shortcut` inherited from [`EventEmitter`](https://nodejs.org/api/events.html#events_class_events_eventemitter). Every time the user presses the registered shortcut, your app will receive an `active` event of the shortcut object.

## Synopsis

```js
var option = {
  key : "Ctrl+Shift+A",
  active : function() {
    console.log("Global desktop keyboard shortcut: " + this.key + " active."); 
  },
  failed : function(msg) {
    // :(, fail to register the |key| or couldn't parse the |key|.
    console.log(msg);
  }
};

// Create a shortcut with |option|.
var shortcut = new nw.Shortcut(option);

// Register global desktop shortcut, which can work without focus.
nw.App.registerGlobalHotKey(shortcut);

// If register |shortcut| successfully and user struck "Ctrl+Shift+A", |shortcut|
// will get an "active" event.

// You can also add listener to shortcut's active and failed event.
shortcut.on('active', function() {
  console.log("Global desktop keyboard shortcut: " + this.key + " active."); 
});

shortcut.on('failed', function(msg) {
  console.log(msg);
});

// Unregister the global desktop shortcut.
nw.App.unregisterGlobalHotKey(shortcut);
```

## new Shortcut(option)

* `option` `{Object}`
    - `key` `{String}` key combinations of the shortcut, such as `"ctrl+shift+a"`. See [shortcut.key](#shortcutkey) property for details.
    - `active` `{Function}` _Optional_ a callback when the hotkey is triggered. See [shortcut.active](#shortcutactive) property for details.
    - `failed` `{Function}` _Optional_ a callback when failed to register the hotkey. See [shortcut.failed](#shortcutfailed) property for details.

Create new `Shortcut`, `option` is an object contains initial settings for the `Shortcut`.

## shortcut.key

Get the `key` of a `Shortcut`. It is a string to specify the shortcut key, like `"Ctrl+Alt+A"`. The key is consisted of zero or more _modifiers_ and a _key_ on your keyboard.

!!! warning "Single Key without Modifiers"
    The API `App.registerGlobalHotKey()` can support applications intercepting a single key (like `{ key: "A"}`). But users will not be able to use "A" normally any more until the app unregisters it. However, the API doesn't limit this usage, and it would be useful if the applications wants to listen Media Keys.
    **Only use zero modifier when you are knowing what your are doing.**

### Supported Modifiers

Following key modifiers are supported. And all modifiers are **case insensitive**.

* `Ctrl`: <kbd>Ctrl</kbd>
* `Alt`: <kbd>Alt</kbd>
* `Shift`: <kbd>Shift</kbd>
* `Command`: `Command` modifier maps to Apple key (<kbd>&#8984;</kbd>) on Mac, and maps to the Windows key on MS Windows and Linux.
* `Cmd`, `Super`: aliases to `Command`

### Supported Keys

All key listed in [W3C DOM Level 3 KeyboardEvent Key Values](http://www.w3.org/TR/DOM-Level-3-Events-key/) are supported, such as `PageDown`, `Home`, `Escape`, `Comma`, `Slash`, `Numpad1` etc. And following aliases can also be used for convenience.

Keys are **case insensitive** and you can have **exactly one key**.

* Alphabet: `a`-`z`
* Digits: `0`-`9`
* Other keys on main area: `[` , `]` , `'` , `,` , `.` , `/` , `` ` `` , `-` , `=` , `\` , `'` , `;`
* Functional Keys: `Esc`
* Arrow Keys: `Down` , `Up` , `Left` , `Right`
* Media Keys: `MediaNextTrack`, `MediaPrevTrack` (backward compatible with 0.12.x)

## shortcut.active

Get or set the `active` callback of a `Shortcut`. It will be called when user presses the shortcut.

## shortcut.failed

*Get or set the `failed` callback of a `Shortcut`. It will be called when application passes an invalid key , or failed to register the key.

## Event:active

Same as [`shortcut.active`](#shortcutactive)

## Event:failed

Same as [`shortcut.failed`](#shortcutfailed)
