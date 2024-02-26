import git
import os

def clone_repo():
    # Hardcoded GitHub repository URL
    repo_url = "https://github.com/07Sushant/Shopping-simulation.git"
    
    # Extracting the repository name from the URL
    repo_name = repo_url.split('/')[-1].replace('.git', '')

    # Specifying the path where the repository will be cloned
    clone_path = os.path.join(os.getcwd(), repo_name)

    try:
        # Cloning the repository
        git.Repo.clone_from(repo_url, clone_path)
        print(f"Repository cloned successfully into '{clone_path}'")
    except git.exc.GitCommandError as e:
        print(f"Error occurred: {e}")

if __name__ == "__main__":
    # Cloning the hardcoded repository
    clone_repo()
