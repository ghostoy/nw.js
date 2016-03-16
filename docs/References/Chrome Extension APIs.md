# Chrome Extension APIs {: .doctitle}
---

[TOC]

!!! tip "NW.js supports **some** of Chrome Extension APIs"
    This document is a snapshot of the [official document](https://developer.chrome.com/extensions/api_index) for the APIs for this release.

Chrome provides extensions with many special-purpose APIs like `chrome.runtime` and `chrome.alarms`.

## Stable APIs

| Name | Description | Since |
|:----:|:----------- |:-----:|
| [accessibilityFeatures](https://developer.chrome.com/extensions/accessibilityFeatures) | Use the `chrome.accessibilityFeatures` API to manage Chrome's accessibility features. This API relies on the [ChromeSetting prototype of the type API](https://developer.chrome.com/extensions/types#ChromeSetting) for getting and setting individual accessibility features. In order to get feature states the extension must request accessibilityFeatures.read permission. For modifying feature state, the extension needs accessibilityFeatures.modify permission. Note that accessibilityFeatures.modify does not imply accessibilityFeatures.read permission. | 37 |
| [alarms](https://developer.chrome.com/extensions/alarms) | Use the `chrome.alarms` API to schedule code to run periodically or at a specified time in the future. | 22 |
| [bookmarks](https://developer.chrome.com/extensions/bookmarks) | Use the `chrome.bookmarks` API to create, organize, and otherwise manipulate bookmarks. Also see [Override Pages](https://developer.chrome.com/extensions/override), which you can use to create a custom Bookmark Manager page. | 5 |
| [browserAction](https://developer.chrome.com/extensions/browserAction) | Use browser actions to put icons in the main Google Chrome toolbar, to the right of the address bar. In addition to its [icon](https://developer.chrome.com/extensions/browserAction#icon), a browser action can also have a [tooltip](https://developer.chrome.com/extensions/browserAction#tooltip), a [badge](https://developer.chrome.com/extensions/browserAction#badge), and a [popup](https://developer.chrome.com/extensions/browserAction#popup). | 5 |
| [browsingData](https://developer.chrome.com/extensions/browsingData) | Use the `chrome.browsingData` API to remove browsing data from a user's local profile. | 19 |
| [certificateProvider](https://developer.chrome.com/extensions/certificateProvider) | Use this API to expose certificates to the platform which can use these certificates for TLS authentications. | 46 |
| [commands](https://developer.chrome.com/extensions/commands) | Use the commands API to add keyboard shortcuts that trigger actions in your extension, for example, an action to open the browser action or send a command to the extension. | 25 |
| [contentSettings](https://developer.chrome.com/extensions/contentSettings) | Use the `chrome.contentSettings` API to change settings that control whether websites can use features such as cookies, JavaScript, and plugins. More generally speaking, content settings allow you to customize Chrome's behavior on a per-site basis instead of globally. | 16 |
| [contextMenus](https://developer.chrome.com/extensions/contextMenus) | Use the `chrome.contextMenus` API to add items to Google Chrome's context menu. You can choose what types of objects your context menu additions apply to, such as images, hyperlinks, and pages. | 6 |
| [cookies](https://developer.chrome.com/extensions/cookies) | Use the `chrome.cookies` API to query and modify cookies, and to be notified when they change. | 6 |
| [debugger](https://developer.chrome.com/extensions/debugger) | The `chrome.debugger` API serves as an alternate transport for Chrome's [remote debugging protocol](https://developer.chrome.com/devtools/docs/debugger-protocol). Use `chrome.debugger` to attach to one or more tabs to instrument network interaction, debug JavaScript, mutate the DOM and CSS, etc. Use the Debuggee tabId to target tabs with sendCommand and route events by tabId from onEvent callbacks. | 18 |
| [declarativeContent](https://developer.chrome.com/extensions/declarativeContent) | Use the `chrome.declarativeContent` API to take actions depending on the content of a page, without requiring permission to read the page's content. | 33 |
| [desktopCapture](https://developer.chrome.com/extensions/desktopCapture) | Desktop Capture API that can be used to capture content of screen, individual windows or tabs. | 34 |
| [devtools.inspectedWindow](https://developer.chrome.com/extensions/devtools.inspectedWindow) | Use the `chrome.devtools.inspectedWindow` API to interact with the inspected window: obtain the tab ID for the inspected page, evaluate the code in the context of the inspected window, reload the page, or obtain the list of resources within the page. | 18 |
| [devtools.network](https://developer.chrome.com/extensions/devtools.network) | Use the `chrome.devtools.network` API to retrieve the information about network requests displayed by the Developer Tools in the Network panel. | 18 |
| [devtools.panels](https://developer.chrome.com/extensions/devtools.panels) | Use the `chrome.devtools.panels` API to integrate your extension into Developer Tools window UI: create your own panels, access existing panels, and add sidebars. | 18 |
| [documentScan](https://developer.chrome.com/extensions/documentScan) | Use the `chrome.documentScan` API to discover and retrieve images from attached paper document scanners. | 44 |
| [downloads](https://developer.chrome.com/extensions/downloads) | Use the `chrome.downloads` API to programmatically initiate, monitor, manipulate, and search for downloads. | 31 |
| [enterprise.deviceAttributes](https://developer.chrome.com/extensions/enterprise.deviceAttributes) | Use the `chrome.enterprise.deviceAttributes` API to read device attributes. | 46 |
| [enterprise.platformKeys](https://developer.chrome.com/extensions/enterprise.platformKeys) | Use the `chrome.enterprise.platformKeys` API to generate hardware-backed keys and to install certificates for these keys. The certificates will be managed by the platform and can be used for TLS authentication, network access or by other extension through [chrome.platformKeys](https://developer.chrome.com/extensions/platformKeys). | 37 |
| [events](https://developer.chrome.com/extensions/events) | The `chrome.events` namespace contains common types used by APIs dispatching events to notify you when something interesting happens. | 21 |
| [extension](https://developer.chrome.com/extensions/extension) | The `chrome.extension` API has utilities that can be used by any extension page. It includes support for exchanging messages between an extension and its content scripts or between extensions, as described in detail in [Message Passing](https://developer.chrome.com/extensions/messaging). | 5 |
| [extensionTypes](https://developer.chrome.com/extensions/extensionTypes) | The `chrome.extensionTypes` API contains type declarations for Chrome extensions. | 39 |
| [fileBrowserHandler](https://developer.chrome.com/extensions/fileBrowserHandler) | Use the `chrome.fileBrowserHandler` API to extend the Chrome OS file browser. For example, you can use this API to enable users to upload files to your website. | 12 |
| [fileSystemProvider](https://developer.chrome.com/extensions/fileSystemProvider) | Use the `chrome.fileSystemProvider` API to create file systems, that can be accessible from the file manager on Chrome OS. | 40 |
| [fontSettings](https://developer.chrome.com/extensions/fontSettings) | Use the `chrome.fontSettings` API to manage Chrome's font settings. | 22 |
| [gcm](https://developer.chrome.com/extensions/gcm) | Use `chrome.gcm` to enable apps and extensions to send and receive messages through the [Google Cloud Messaging Service](http://developer.android.com/google/gcm/). | 35 |
| [history](https://developer.chrome.com/extensions/history) | Use the `chrome.history` API to interact with the browser's record of visited pages. You can add, remove, and query for URLs in the browser's history. To override the history page with your own version, see [Override Pages](https://developer.chrome.com/extensions/override). | 5 |
| [i18n](https://developer.chrome.com/extensions/i18n) | Use the `chrome.i18n` infrastructure to implement internationalization across your whole app or extension. | 5 |
| [identity](https://developer.chrome.com/extensions/identity) | Use the `chrome.identity` API to get OAuth2 access tokens. | 29 |
| [idle](https://developer.chrome.com/extensions/idle) | Use the `chrome.idle` API to detect when the machine's idle state changes. | 6 |
| [input.ime](https://developer.chrome.com/extensions/input.ime) | Use the `chrome.input.ime` API to implement a custom IME for Chrome OS. This allows your extension to handle keystrokes, set the composition, and manage the candidate window. | 21 |
| [instanceID](https://developer.chrome.com/extensions/instanceID) | Use `chrome.instanceID` to access the Instance ID service. | 46 |
| [management](https://developer.chrome.com/extensions/management) | The `chrome.management` API provides ways to manage the list of extensions/apps that are installed and running. It is particularly useful for extensions that [override](https://developer.chrome.com/extensions/override) the built-in New Tab page. | 8 |
| [networking.config](https://developer.chrome.com/extensions/networking.config) | Use the networking.config API to authenticate to captive portals. | 43 |
| [notifications](https://developer.chrome.com/extensions/notifications) | Use the `chrome.notifications` API to create rich notifications using templates and show these notifications to users in the system tray. | 28 |
| [omnibox](https://developer.chrome.com/extensions/omnibox) | The omnibox API allows you to register a keyword with Google Chrome's address bar, which is also known as the omnibox. | 9 |
| [pageAction](https://developer.chrome.com/extensions/pageAction) | Use the `chrome.pageAction` API to put icons in the main Google Chrome toolbar, to the right of the address bar. Page actions represent actions that can be taken on the current page, but that aren't applicable to all pages. Page actions appear grayed out when inactive. | 5 |
| [pageCapture](https://developer.chrome.com/extensions/pageCapture) | Use the `chrome.pageCapture` API to save a tab as MHTML. | 18 |
| [permissions](https://developer.chrome.com/extensions/permissions) | Use the `chrome.permissions` API to request [declared optional permissions](https://developer.chrome.com/extensions/permissions#manifest) at run time rather than install time, so users understand why the permissions are needed and grant only those that are necessary. | 16 |
| [platformKeys](https://developer.chrome.com/extensions/platformKeys) | Use the `chrome.platformKeys` API to access client certificates managed by the platform. If the user or policy grants the permission, an extension can use such a certficate in its custom authentication protocol. E.g. this allows usage of platform managed certificates in third party VPNs (see [chrome.vpnProvider](https://developer.chrome.com/extensions/vpnProvider)). | 45 |
| [power](https://developer.chrome.com/extensions/power) | Use the `chrome.power` API to override the system's power management features. | 27 |
| [printerProvider](https://developer.chrome.com/extensions/printerProvider) | The `chrome.printerProvider` API exposes events used by print manager to query printers controlled by extensions, to query their capabilities and to submit print jobs to these printers. | 44 |
| [privacy](https://developer.chrome.com/extensions/privacy) | Use the `chrome.privacy` API to control usage of the features in Chrome that can affect a user's privacy. This API relies on the [ChromeSetting prototype of the type API](https://developer.chrome.com/extensions/types#ChromeSetting) for getting and setting Chrome's configuration. | 18 |
| [proxy](https://developer.chrome.com/extensions/proxy) | Use the `chrome.proxy` API to manage Chrome's proxy settings. This API relies on the [ChromeSetting prototype of the type API](https://developer.chrome.com/extensions/types#ChromeSetting) for getting and setting the proxy configuration. | 13 |
| [runtime](https://developer.chrome.com/extensions/runtime) | Use the `chrome.runtime` API to retrieve the background page, return details about the manifest, and listen for and respond to events in the app or extension lifecycle. You can also use this API to convert the relative path of URLs to fully-qualified URLs. | 22 |
| [sessions](https://developer.chrome.com/extensions/sessions) | Use the `chrome.sessions` API to query and restore tabs and windows from a browsing session. | 37 |
| [storage](https://developer.chrome.com/extensions/storage) | Use the `chrome.storage` API to store, retrieve, and track changes to user data. | 20 |
| [system.cpu](https://developer.chrome.com/extensions/system.cpu) | Use the system.cpu API to query CPU metadata. | 32 |
| [system.memory](https://developer.chrome.com/extensions/system.memory) | The `chrome.system.memory` API. | 32 |
| [system.storage](https://developer.chrome.com/extensions/system.storage) | Use the `chrome.system.storage` API to query storage device information and be notified when a removable storage device is attached and detached. | 30 |
| [tabCapture](https://developer.chrome.com/extensions/tabCapture) | Use the `chrome.tabCapture` API to interact with tab media streams. | 31 |
| [tabs](https://developer.chrome.com/extensions/tabs) | Use the `chrome.tabs` API to interact with the browser's tab system. You can use this API to create, modify, and rearrange tabs in the browser. | 5 |
| [topSites](https://developer.chrome.com/extensions/topSites) | Use the `chrome.topSites` API to access the top sites that are displayed on the new tab page. | 19 |
| [tts](https://developer.chrome.com/extensions/tts) | Use the `chrome.tts` API to play synthesized text-to-speech (TTS). See also the related [ttsEngine](https://developer.chrome.com/extensions/ttsEngine) API, which allows an extension to implement a speech engine. | 14 |
| [ttsEngine](https://developer.chrome.com/extensions/ttsEngine) | Use the `chrome.ttsEngine` API to implement a text-to-speech(TTS) engine using an extension. If your extension registers using this API, it will receive events containing an utterance to be spoken and other parameters when any extension or Chrome App uses the [tts](https://developer.chrome.com/extensions/tts) API to generate speech. Your extension can then use any available web technology to synthesize and output the speech, and send events back to the calling function to report the status. | 14 |
| [types](https://developer.chrome.com/extensions/types) | The `chrome.types` API contains type declarations for Chrome. | 13 |
| [vpnProvider](https://developer.chrome.com/extensions/vpnProvider) | Use the `chrome.vpnProvider` API to implement a VPN client. | 43 |
| [wallpaper](https://developer.chrome.com/extensions/wallpaper) | Use the `chrome.wallpaper` API to change the ChromeOS wallpaper. | 31 |
| [webNavigation](https://developer.chrome.com/extensions/webNavigation) | Use the `chrome.webNavigation` API to receive notifications about the status of navigation requests in-flight. | 16 |
| [webRequest](https://developer.chrome.com/extensions/webRequest) | Use the `chrome.webRequest` API to observe and analyze traffic and to intercept, block, or modify requests in-flight. | 17 |
| [webstore](https://developer.chrome.com/extensions/webstore) | Use the `chrome.webstore` API to initiate app and extension installations "inline" from your site. | 15 |
| [windows](https://developer.chrome.com/extensions/windows) | Use the `chrome.windows` API to interact with browser windows. You can use this API to create, modify, and rearrange windows in the browser. | 5 |

## Beta APIs

These APIs are only available in the Chrome Beta and Dev channels:

| Name | Description |
|:----:|:----------- |
| [declarativeWebRequest](https://developer.chrome.com/extensions/declarativeWebRequest) | Note: this API is currently on hold, without concrete plans to move to stable. Use the `chrome.declarativeWebRequest` API to intercept, block, or modify requests in-flight. It is significantly faster than the [chrome.webRequest API](https://developer.chrome.com/extensions/webRequest) because you can register rules that are evaluated in the browser rather than the JavaScript engine with reduces roundtrip latencies and allows higher efficiency. |

## Dev APIs

These APIs are only available in the Chrome Dev channel:

| Name | Description |
|:----:|:----------- |
| [automation](https://developer.chrome.com/extensions/automation) | The `chrome.automation` API allows developers to access the automation (accessibility) tree for the browser. The tree resembles the DOM tree, but only exposes the semantic structure of a page. It can be used to programmatically interact with a page by examining names, roles, and states, listening for events, and performing actions on nodes. |
| [processes](https://developer.chrome.com/extensions/processes) | Use the `chrome.processes` API to interact with the browser's processes. |
| [signedInDevices](https://developer.chrome.com/extensions/signedInDevices) | Use the `chrome.signedInDevices` API to get a list of devices signed into chrome with the same account as the current profile. |

## Experimental APIs

Chrome also has [experimental APIs](https://developer.chrome.com/extensions/experimental), some of which will become supported APIs in future releases of Chrome.

## API conventions

Unless the doc says otherwise, methods in the chrome.* APIs are **asynchronous**: they return immediately, without waiting for the operation to finish. If you need to know the outcome of an operation, then you pass a callback function into the method. For more information, watch this video:

See video at https://developer.chrome.com/extensions/api_index#conventions

*Content available under the [CC-By 3.0 license](http://creativecommons.org/licenses/by/3.0/)*