// Function : FUN_400e8448
// Address  : 0x400e8448
// Size     : 32 bytes


undefined4 FUN_400e8448(undefined4 param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_400e81d0();
  uVar2 = 1;
  if ((uVar1 & 1) != (param_2 & 0xff)) {
    if ((param_2 & 0xff) == 0) {
      uVar1 = uVar1 & 0xfffffffe;
    }
    else {
      uVar1 = uVar1 | 1;
    }
    uVar2 = FUN_400e81f4(uVar1);
  }
  return uVar2;
}

