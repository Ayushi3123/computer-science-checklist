import React, { Component } from 'react';
import { Text, TouchableWithoutFeedback, View } from "react-native";
import { CardSection } from './common'
import { Actions } from 'react-native-router-flux';

class ListItem extends Component {
    render() {
        const { name } = this.props.employee;

        return (
            <TouchableWithoutFeedback onPress={this.onRowPress.bind(this)}>
                <View>
                    <CardSection>
                        <Text style={styles.titleStyle}>
                            {name}
                        </Text>
                    </CardSection>
                </View>
            </TouchableWithoutFeedback>
        );
    }

    onRowPress() {
        Actions.employeeEdit({ employee: this.props.employee });
    }

}

const styles = {
    titleStyle: {
        fontSize: 18,
        paddingLeft: 15
    }
}

export default ListItem;