import {
    EMPLOYEES_FETCH_SUCCESS
} from '../actions/types';

const INITITAL_STATE = {};

export default (state = INITITAL_STATE, action) => {
    switch (action.type) {
        case EMPLOYEES_FETCH_SUCCESS:
            return action.payload;
        default:
            return state;
    }
}