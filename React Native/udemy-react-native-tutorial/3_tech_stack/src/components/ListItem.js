import React, { Component } from 'react';
import { Text, TouchableWithoutFeedback, View, LayoutAnimation, UIManager, Platform } from 'react-native';
import { connect } from 'react-redux';
import { CardSection } from './common';
import * as actions from '../actions';

if (Platform.OS === 'android')
    UIManager.setLayoutAnimationEnabledExperimental(true);


class ListItem extends Component {

    componentWillUpdate() {
        LayoutAnimation.spring();
    }

    render() {
        const { titleStyle } = styles;
        const { id, title, description } = this.props.library;


        return (
            <TouchableWithoutFeedback onPress={() => this.props.selectLibrary(id)}>
                <View>
                    <CardSection>
                        <Text style={titleStyle}>
                            {title}
                        </Text>

                    </CardSection>
                    {this.renderDescription()}
                </View>
            </TouchableWithoutFeedback>
        );
    }

    renderDescription() {
        const { library, expanded } = this.props;
        if (expanded)
            return (
                <CardSection>
                    <Text style={{ flex: 1, paddingLeft: 15, paddingRight: 15, fontSize: 16 }}>{library.description}</Text>
                </CardSection>
            );
    }


}

const styles = {
    titleStyle: {
        fontSize: 18,
        paddingLeft: 15,
        paddingTop: 25,
        paddingBottom: 25

    }
}

const mapStateToProps = (state, ownProps) => {
    return {
        expanded: state.selectedLibraryId === ownProps.library.id
    };
}

export default connect(mapStateToProps, actions)(ListItem);