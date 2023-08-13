// background.js
chrome.commands.onCommand.addListener(command => {
    if (command === "open_tab_shortcut") {
      chrome.tabs.create({ url: "https://www.example.com" }); // Replace the URL with the desired target page
    }
  });
