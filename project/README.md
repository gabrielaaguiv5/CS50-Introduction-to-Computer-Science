# TABS SORTER
### Video Demo:  <URL https://youtu.be/UkEH8--KTRg>
### Description: Tab Sorter: Easing Navigation in Tab-Overloaded Scenarios. My name is Gabriela Aguilar, I am from Colombia, and I am 24 years old. I am a Civil Engineer, but I currently find myself in the search of a new career path, particularly interested in Computer Science. While I fulfill the academic requirements, I work as an assistant, and is in my day-to-day as such that I got the inspiration for this current project. As an assistant, my job requires me to work on multiple fronts and to manipulate a lot of information, at the same time. When worst comes to worst, the number of tabs gets impossible to navigate. This is the origin of my idea: I Wanted a tool that would help me get from one tab to the other, quickly, and without having to open several different tabs in the way of reaching the one I need. I recalled the setup of the tabs in the navigator app on our phones. On my iPhone, after a simple couple of clicks, I am able to scroll and reach the tab I need very quickly. On the computer setup is a different story. I work with a lot of spreadsheet files online, all with the same icon, as well as I sometimes need multiple Gmail tabs to be opened simultaneously. What I needed was an accessible version of the tabs on my phone: a list, that gave me the same title from the tab's bar, which helped me not have to fight between same-icon websites, to find the information I need. Have I mentioned being an assistant requires me to come up with quick answers and fast solutions?
#### Author: Gabriela Lucía Aguilar Velásquez.
#### City: Cartagena.
#### Country: Colombia, 2023.
#### Creation: Google Chrome Extension.
#### The development: Reading the documentation I was able to identify the key elements necessary to put together and launch a successful Chrome Extension. The files I detail as follows.
#### The files:
1. Folders:
    1. images: Contains the icons .png files, which I created in Canvas.
    2. styles: Contains the .css file, which styled both the Pop Up and the Options page.
2. Files:
    1. manifest.json: Main information of version, name, author, icons, and permissions of the Extension.
    2. popup.html: The Front End part of the Extension. HTML file which dictates the look the user gets of the Extension, via a Pop Up, and where the .js code gets called.
    3. popup.css: CSS file which dictates the style for all the elements in the HTML files.
    4. popup.js: Contains the JavaScript code that allows the Extension to work. The ID of each opened tab, on a current Chrome Window, gets organized in a programmed list, in which every new <li> element is a "link" which emulates the "clicking" action to get to a tab.
    5. options.html: Gives explination "Simply click on the tab that is listed to be redirected. Only will work within the tabs on the same window. If multiple windows are open the list of tabs will be unique on each one."
#### The results: Tab Sorter was tested by uploading to my Chrome. It does allow me to get from a tab to another by navigating the list compiled on the Pop Up.
### Thank You CS50! Hope you like it!