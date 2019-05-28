defmodule Libp2pDaemon do
  @moduledoc """
  Starts and stops the libp2p daemon from Elixir.
  """

  @on_load {:init, 0}

  # loading the NIF
  def init do
    path = :filename.join(:code.priv_dir(unquote(app)), 'parser')
    :ok = :erlang.load_nif(path, 0)
  end

  @doc """
  Starts the libp2p daemon with given configuration.
  """
  def start(config) do
    p2pd.start(config)
  end

  @doc """
  Stops the libp2p daemon.
  """
  def stop() do
    p2pd.stop()
  end
end
