class JsonWebToken
	# Secret used to encode/decode token
	HMAC_SECRET = Rails.application.secrets.secret_key_base

	def self.encode(payload, exp = 24.hours.from_now)
		# set the expiry time
		payload[:exp] = exp.to_i
		# encode the token
		JWT.encode(payload, HMAC_SECRET)
	end

	def self.decode(token)
		# get the payload
		body = JWT.decode(token, HMAC_SECRET)[0]
		HashWithIndifferentAccess.new body
		# catch errors
	rescue JWT::DecodeError => e
		raise ExceptionHandler::InvalidToken, e.message
	# rescue JWT::DecodeError, JWT::ExpiredSignature => e
	# 	# raise a custom error to be handled by custom handler
	# 	raise ExceptionHandler::InvalidToken, e.message
	end
end