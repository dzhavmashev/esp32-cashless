// Function : FUN_400de604
// Address  : 0x400de604
// Size     : 48 bytes


undefined4 FUN_400de604(undefined4 param_1,ushort param_2)

{
  undefined4 uVar1;
  
  uVar1 = 4;
  if (param_2 < 100) {
    if (param_2 < 0x400d) {
      uVar1 = 0xff;
    }
    else {
      uVar1 = 3;
    }
  }
  return uVar1;
}

