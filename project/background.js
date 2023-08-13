chrome.runtime.onInstalled.addListener(() => {
    // default state goes here
    // this runs ONE TIME ONLY (unless the user reinstalls your extension)
});

// content_script.js
const titleColor = 'red'; // Change this color to your desired display color

// Function to change tab title color
function changeTabTitleColor() {
  document.title = `%c${document.title}`;
  document.title = document.title.replace('%c', `%c${titleColor}`);
}

// Listen for page load event and update the tab title color
window.addEventListener('load', changeTabTitleColor);