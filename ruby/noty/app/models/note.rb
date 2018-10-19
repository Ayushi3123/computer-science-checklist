class Note
  include Mongoid::Document
  include Mongoid::Timestamps

  field :title,   type: String
  field :content, type: String

  validates :title, presence: true
  validates :content, presence: true

  belongs_to :user
end
