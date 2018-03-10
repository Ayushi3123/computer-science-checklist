import React, { Component } from 'react';
import { View, Text } from "react-native";
import { connect } from 'react-redux';
import { emailChanged, passwordChanged, loginUser } from '../actions';
import { Card, Input, CardSection, Button, Spinner } from './common';


class LoginForm extends Component {
    render() {
        return (
            <Card>
                <CardSection>
                    <Input label="Email"
                        value={this.props.email}
                        placeholder="email@gmail.com"
                        onChangeText={this.onEmailChange.bind(this)} />
                </CardSection>
                <CardSection>
                    <Input label="Password"
                        secureTextEntry
                        placeholder="password"
                        value={this.props.password}
                        onChangeText={this.onPasswordChange.bind(this)} />
                </CardSection>
                {this.renderError()}

                {this.renderButton()}
            </Card>
        );
    }

    renderError() {
        if (this.props.error)
            return (
                <View style={{ backgroundColor: 'white' }}>
                    <Text style={styles.errorTextStyle}>
                        {this.props.error}
                    </Text>
                </View>
            );
    }

    renderButton() {
        if (this.props.loading)
            return (
                <CardSection>
                    <Spinner />
                </CardSection>
            );
        else
            return (
                <CardSection>
                    <Button onPress={this.onButtonPress.bind(this)}>
                        Login
                </Button>
                </CardSection>
            );
    }


    onEmailChange(text) {
        this.props.emailChanged(text);
    }

    onPasswordChange(text) {
        this.props.passwordChanged(text);
    }

    onButtonPress() {
        const { email, password } = this.props;
        this.props.loginUser({ email, password });
    }
}

const styles = {
    errorTextStyle: {
        fontSize: 20,
        alignSelf: 'center',
        color: 'red'
    }
}

const mapStateToProps = state => {
    return {
        email: state.auth.email,
        password: state.auth.password,
        error: state.auth.error,
        loading: state.auth.loading
    }
};

export default connect(mapStateToProps, { emailChanged, passwordChanged, loginUser })(LoginForm);