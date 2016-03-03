# Frog Form

Frog Form is a native Visual C++.NET program for Windows 10.

## How to build

 - Open the .sln using [Visual Studio 2015](https://www.visualstudio.com/en-us/downloads/download-visual-studio-vs.aspx)
 - Install an instance of [SQL Server 2016](https://www.microsoft.com/en-us/server-cloud/products/sql-server-2016/)
 - Use SQL Server Management Studio (or CLI if you're good) to manage the .sdf
 
 ## Some tips on managed code for C++
 - `new` keyword is replaced with `gcnew`
 - `'some string'` is prefixed like `L'some string'` for display text
 - `object.function()` is `object->function()` and `object.property` is `object->property`
 
