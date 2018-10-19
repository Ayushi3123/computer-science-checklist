class NotesController < ApplicationController
    before_action :authenticate_user!

    def index 
        @notes = Note.where(:user_id => current_user._id).desc(:updated_at).all()
    end

    def new
        @note = Note.new
    end
    
    def create
        new_note = Note.new note_params
        new_note.user_id = current_user._id
        new_note.save

        redirect_to '/notes'
    end

    def edit
        @note = find_note
    end

    def update
        find_note.update note_params
        redirect_to '/notes'
    end

    private

    def note_params
        params.require(:note).permit(:title, :content)
    end

    def find_note
        note = Note.find params[:id]
        if note.user_id != current_user._id
            redirect_to '/notes'
        end

        note
    end
end
