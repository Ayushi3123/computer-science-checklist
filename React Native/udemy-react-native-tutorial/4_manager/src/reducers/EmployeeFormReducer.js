import {
    EMPLOYEE_UPDATE,
    EMPLOYEE_CREATE,
    EMPLOYEE_SAVE_SUCCESS
} from '../actions/types';

const INITITAL_STATE = {
    name: '',
    phone: '',
    shift: ''
};

export default (state = INITITAL_STATE, action) => {
    switch (action.type) {
        case EMPLOYEE_UPDATE:
            // action.payload = {prop:'name',value:'Jaco'}
            console.log({ ...state, [action.payload.prop]: action.payload.value });
            return { ...state, [action.payload.prop]: action.payload.value }
        case EMPLOYEE_CREATE:
            return INITITAL_STATE;
        case EMPLOYEE_SAVE_SUCCESS:
            return INITITAL_STATE;
        default:
            return state;
    }
}