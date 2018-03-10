import React, { Component } from 'react';
import { Text } from 'react-native';
import firebase from 'firebase';
import { Card, Button, CardSection, Input, Spinner } from './common';

class LoginForm extends Component {
    state = {
        email: '',
        password: '',
        error: '',
        loading: false
    };

    render() {
        return (
            <Card>
                <CardSection>
                    <Input
                        label="Email"
                        placeholder="user@gmail.com"
                        value={this.state.email}
                        onChangeText={email => this.setState({ email })} />
                </CardSection>
                <CardSection>
                    <Input
                        label="Password"
                        placeholder="password"
                        value={this.state.password}
                        onChangeText={password => this.setState({ password })}
                        secureTextEntry />
                </CardSection>

                {this.state.error.length > 0 && <Text style={styles.errorTextStyle}>
                    {this.state.error}
                </Text>}

                <CardSection>
                    {this.renderButton()}
                </CardSection>
            </Card>
        )
    }

    renderButton() {
        if (this.state.loading)
            return (<Spinner />);

        return (<Button onPress={this.onButtonPress.bind(this)}>
            Log In
        </Button>);
    }

    onButtonPress() {
        const { email, password } = this.state;

        this.setState({ error: '', loading: true });

        firebase.auth().signInWithEmailAndPassword(email, password)
            .then(this.onLoginSuccess.bind(this))
            .catch(err => {
                firebase.auth().createUserWithEmailAndPassword(email, password)
                    .then(this.onLoginSuccess.bind(this))
                    .catch(this.onLoginFail.bind(this));
            });
    }

    onLoginSuccess() {
        this.setState({ error: '', loading: false, email: '', password: '' });
    }

    onLoginFail() {
        this.setState({ error: 'Authentication Failed.', loading: false });
    }
}

const styles = {
    errorTextStyle: {
        fontSize: 20,
        alignSelf: 'center',
        color: 'red'
    }
}

export default LoginForm;