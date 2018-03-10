import React, { Component } from 'react';
import { View, Text } from 'react-native';
import { Provider } from 'react-redux';
import { createStore, applyMiddleware } from 'redux';
import reducers from './reducers';
import firebase from 'firebase';
import ReduxThunk from 'redux-thunk';

import LoginForm from './components/LoginForm';

import RouterComponent from "./Router";


class App extends Component {
    componentWillMount() {
        firebase.initializeApp({
            apiKey: "AIzaSyDVD9GIoitl0gw4RunPTrB89XUWRlif5EE",
            authDomain: "manager-80632.firebaseapp.com",
            databaseURL: "https://manager-80632.firebaseio.com",
            projectId: "manager-80632",
            storageBucket: "manager-80632.appspot.com",
            messagingSenderId: "101663586010"
        });
    }

    render() {
        const store = createStore(reducers, {}, applyMiddleware(ReduxThunk));

        return (
            <Provider store={store}>
                <RouterComponent />
            </Provider>
        );
    }
};

export default App;