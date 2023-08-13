// Tabs Sorter by Gabriela Aguilar 2023 - Back End

chrome.tabs.query({currentWindow: true}, tabs => // Just access to tabs on the current Window
  {
  const tabList = document.getElementById('tabList'); // Access to the ID of each tab - This will become the list
  tabs.forEach(tab =>
    {
    const listTab = document.createElement('li'); // Makes each Tab into a li element for the <ul> in popup.html
    const link = document.createElement('a'); // Makes each li element into a shortcut for the currently opened Tab

    link.textContent = tab.title || tab.url; // The text on the list will be exacltly how the Tab's shown in the browser's title bar
    link.href = '#'; // Placeholder for the link that will be created for Tab shortcut
    link.addEventListener('click', event => // The link/shortcut replicates the clicking action
    {
      event.preventDefault(); // To prevent for link to open brand new Tab, since the intention is to redirect
      activateTab(tab.id);  // The event involves for a click to replicate clicking on a Tab in the current Window, hence redirecting
    });

    listTab.appendChild(link);
    tabList.appendChild(listTab);
  });
});

function activateTab(tabId) {
  chrome.tabs.update(tabId, { active: true });
  window.close(); // Close the Pop Up after activating the tab
}