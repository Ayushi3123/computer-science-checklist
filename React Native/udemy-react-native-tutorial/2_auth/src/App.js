import React, { Component } from 'react';
import { View, Dimensions } from 'react-native';
import firebase from 'firebase';
import { Header, Button, CardSection, Spinner } from './components/common'
import LoginForm from './components/LoginForm';


class App extends Component {
    state = {
        loggedIn: null
    };

    componentWillMount() {
        // Initialize Firebase
        firebase.initializeApp({
            apiKey: "AIzaSyDAnAmzGpTpLpnOmdEOVCrPHKB6N3Hnajg",
            authDomain: "authentication-6c5e5.firebaseapp.com",
            databaseURL: "https://authentication-6c5e5.firebaseio.com",
            projectId: "authentication-6c5e5",
            storageBucket: "authentication-6c5e5.appspot.com",
            messagingSenderId: "920504031584"
        });

        firebase.auth().onAuthStateChanged(user => {
            if (user)
                this.setState({ loggedIn: true })
            else
                this.setState({ loggedIn: false })
        });
    }

    render() {
        return (
            <View>
                <Header headerText="Authentication" />
                {this.renderContent()}
            </View>
        );
    }

    renderContent() {
        switch (this.state.loggedIn) {
            case true:
                return (
                    <CardSection>
                        <Button onPress={() => {firebase.auth().signOut()}}>
                            Log Out
                        </Button>
                    </CardSection>
                );
                break;
            case false:
                return <LoginForm />
                break;
            default:
                return (
                    <View style={styles.fullscreenContainerStyle}>
                        <Spinner />
                    </View>
                )
                break;
        }
    }
}

const styles = {
    fullscreenContainerStyle: {
        flex: 1,
        minHeight: Dimensions.get('window').height - 60
    }
}

export default App;