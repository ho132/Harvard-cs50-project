# cs50 pset9 Finance webb app

## Full-stack web app made with Bootstrap, Flask back-end, and SQLite3 database.

C$50 Finance is a web app via which you can manage portfolios of stocks. Not only will this tool allow you to check real stocks’ actual prices and portfolios’ values, it will also let you buy (okay, “buy”) and sell (okay, “sell”) stocks by querying IEX for stocks’ prices.

To use this project after you forked the repo, you will need to get an API key from [IEX](iexcloud.io/cloud-login#/register/) (free account registration), which lets you download stock quotes via their API.

Visit [IEX](iexcloud.io/cloud-login#/register/)

- Select the “Individual” account type, then enter your name, email address, and a password, and click “Create account”.
- Once registered, scroll down to “Get started for free” and click “Select Start plan” to choose the free plan.
- Once you’ve confirmed your account via a confirmation email, visit https://iexcloud.io/console/tokens.
  Copy the KEY that appears under the Token column (it should begin with pk\_).

With the KEY, run the following command within an IDE's terminal: $ export API_KEY=KEY.

Start Flask’s built-in web server:
$ flask run

## This app features

- register, quote, buy, index, sell and history templates with Jinja dynamic content generation
- app.py (lots of routing, logics, and Sqlite3 QUERIES)
- `users`and`portfolio` tables to keep track of all stock and transactions by all users. It is stored in finance.db
- requirements.txt to install
- helpers.py that implements apology page, login, lookup symbols and formats currencies in USD.

## Flask app file structure:

• app.py

• requirements.txt

• static/

• templates/

## MODEL-VIEW-CONTROLLER (MVC)

design pattern

- model=SQL(..) the database, - view=what user sees, templates,

- controller=application.py, the logics that connect M-V, plus routing

- jinja: Used in HTML templates: {{ var }} , {% block x %} {% endblock %}.

Make use of TEMPLATES: factor out a COMMON layout.html

- {% block body %} {% endblock %}
- in index.html, about.html, etc.: {% extends "layout.html" %} {% block body %} the content {% endblock %}



