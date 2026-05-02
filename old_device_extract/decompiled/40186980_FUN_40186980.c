// Function : FUN_40186980
// Address  : 0x40186980
// Size     : 24 bytes


undefined4 FUN_40186980(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != '\0') && (uVar1 = 2, param_1 == '\x01')) {
    uVar1 = 1;
  }
  return uVar1;
}

