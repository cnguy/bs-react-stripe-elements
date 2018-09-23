# bs-react-stripe-elements

## Introduction

Minimal, hand-generated BuckleScript + ReasonReact bindings for [react-stripe-elements](https://github.com/stripe/react-stripe-elements).

**State**: *experimental, but active. unpublished and requires polishing*

## Examples / Demo

### Main Demo

* [Demo Site](https://bs-react-stripe-elements.surge.sh)
  * [Code for Demo Site](https://github.com/cnguy/bs-react-stripe-elements/blob/master/examples/Checkout)

Note that these examples are not runnable. You would have to copy the files to your own React app to test them. For testing the bindings, I just constantly `yarn add <path-to-local-directory-of-bs-stripe-react-elements>` within a different web app to get the updated changes.

This demo ideally will match [Stripe's own basic demo](https://github.com/stripe/react-stripe-elements/blob/master/demo/demo/index.js).

### Component Demos

TBD. I will add specific component usage (styling a CardElement for example).


## Installation

### 1

Since the package is currently unpublished, we do not use `npm`. Instead,
we rely on the `master` branch.

* With `yarn`

```yarn add cnguy/bs-react-stripe-elements#master```

* With `npm`

```npm install --save cnguy/bs-react-stripe-elements#master```

### 2

Add `@cnguy/bs-react-stripe-elements` to `bsconfig.json` `bs-dependencies`.

### 3

Add `Stripe.js` to your `index.html` file as well. Put it before your app's JS bundle.

```html
<html>
<head />
<body>
  <div id="root" />
  <script src="https://js.stripe.com/v3/"></script>
  <script src="bundle.js"></script>
</body>
</html>
```

## Changes

Currently unpublished. `master` branch will be the "releases" while the `development` branch will be where we'll be working.

Goal is to figure out all issues and publish a `v0.0.1` that implements a majority of the API's.

## Contributing

Hi! I'm Chau. This is my first `Reason` binding, and it's mostly experimental, but I really, really want to polish it, especially because I think Stripe is cool. Also, I use a lot of Reason libraries made by amazing community members, and so I want to try to give back in some way.

All contributions are welcome, whether it's fixing bugs, advice, or important questions (how will I deal with style props for example? will I make a wrapper, convenient API? etc).

I'm pretty active, so don't hesitate to post an issue or send a pull request.
