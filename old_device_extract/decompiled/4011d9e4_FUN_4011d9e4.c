// Function : FUN_4011d9e4
// Address  : 0x4011d9e4
// Size     : 35 bytes


undefined4 FUN_4011d9e4(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = 5;
  if ((byte)(param_1 + 0x10U) < 0x11) {
    uVar1 = *(undefined4 *)("lwip_netconn_is_err_msg" + param_1 * -4 + 0x16);
  }
  return uVar1;
}

