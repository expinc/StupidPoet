import os
import pathlib
import pytest


def test_ordinary():
    rootdir = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    os.environ["STUPID_POETRY_TRAIN_DATA"] = os.path.join(rootdir, "data", "train", "test", "inputs")
    os.environ["STUPID_POETRY_MODEL_OUTPUT"] = os.path.join(rootdir, "data", "train", "test", "outputs")

    try:
        os.makedirs(os.environ["STUPID_POETRY_MODEL_OUTPUT"])
    except FileExistsError:
        pass

    os.system("learn.exe")

    expectedModel = open(os.path.join(rootdir, "data", "train", "test", "expects", "model.json"), "r", encoding="utf8").read()
    actualModel = open(os.path.join(os.environ["STUPID_POETRY_MODEL_OUTPUT"], "model.json"), "r", encoding="utf8").read()
    assert expectedModel == actualModel
