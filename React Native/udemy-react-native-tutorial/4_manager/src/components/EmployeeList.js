import _ from 'lodash';
import React, { Component } from 'react';
import { connect } from "react-redux";
import { View, Text, ListView } from 'react-native';
import { employeesFetch } from "../actions";
import ListItem from './ListItem';

class EmployeeList extends Component {
    componentWillMount() {
        this.props.employeesFetch();
        this.createDataSource(this.props);

    }

    componentWillReceiveProps(nextProps) {
        // next set of props to render
        // this.props is the old collection of properties
        this.createDataSource(nextProps);

    }

    createDataSource({ employees }) {
        const ds = new ListView.DataSource({
            rowHasChanged: (r1, r2) => r1 !== r2
        });

        this.dataSource = ds.cloneWithRows(employees);
    }

    renderRow(employee) {
        return (<ListItem employee={employee} />);
    }

    render() {
        return (
            <ListView
                enableEmptySections
                dataSource={this.dataSource}
                renderRow={this.renderRow}
            />
        );
    }
}

const mapStateToProps = state => {
    const employees = _.map(state.employees, (val, uid) => {
        console.log(val, uid);
        return { ...val, uid }
    });

    return { employees }
};

export default connect(mapStateToProps, { employeesFetch })(EmployeeList);