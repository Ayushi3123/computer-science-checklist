require 'rails_helper'

RSpec.describe AuthenticateUser do
	let(:user) { create(:user) }

	subject(:valid_auth_object) { described_class.new(user.email, user.password) }

	subject(:invalid_auth_obj) { described_class.new('foo', 'bar') }

	describe '#call' do
		context 'when credentials valid' do
			it 'returns an auth token' do
				token = valid_auth_object.call
				expect(token).not_to be_nil
			end
		end

		context 'when credentials invalid' do
			it 'raises an authentication error' do
				expect { invalid_auth_obj.call }.to raise_error(ExceptionHandler::AuthenticationError, /Invalid credentials/)
			end
		end
	end

end