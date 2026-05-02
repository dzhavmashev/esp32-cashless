// Function : FUN_40185a10
// Address  : 0x40185a10
// Size     : 23 bytes


undefined4 FUN_40185a10(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((param_1 != '\x01') && (uVar1 = 4, param_1 != '\x03')) {
    uVar1 = 0;
  }
  return uVar1;
}

