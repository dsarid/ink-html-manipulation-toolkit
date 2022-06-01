
# ink html manipulation toolkit

## Description
A  package of programs for server-side usage, made in c and cgi.

For now the only feature it has is linking blocks of HTML code into the HTML file requested by htttp


## Visuals
I may add later

## Installation
### for server usage:
Simply compile with:
```code 
gcc /path/to/the/source/ -o nameo-of-your-choice
```
Then you need to create the directory: /etc/html-blocks
Inside this directory you need to put your html blocks with .html extension (for example: haeder.html, nav.html, footer.html)

Last thing you need to do is to configure your web server to call this program for every request that end with .html extension

## Usage
Inside your website's html files, whenever you want to insert one of the blocks you made insert a line formated like this:
```code 
<!-- @@ "name-of-the-block" -->
```
Do not include the file extension.

## Support
Tell people where they can go to for help. It can be any combination of an issue tracker, a chat room, an email address, etc.

## Roadmap
I am plannig to add a bunch of stuff! too many in fact.

## Contributing
DISCLAMER: I made this project mainly for my own learning and practing purposes.
Therefore, this code may not be the best to contribute to, let alone use in production.
But I appreachiate your interest nonetheless!

I accept cnotribution, it would be better if you contact me before sending a push request,
but eitherway I'd review your submission and decide if I want to add it to the project or not.

This program in its final form designed to work only with web-servers. If you stil want to debug it without a web-server
you need to replace the get_env() calls with argv[] calls and make sure that you make a valid path to a directory that mimc the use of /etc/html-blocks/ (or make one as root)

## Authors and acknowledgment
I'll add later

## License
This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.

 You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 

## Project status
This project is in active development
