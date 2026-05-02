// Function : FUN_4012c96c
// Address  : 0x4012c96c
// Size     : 60 bytes


uint FUN_4012c96c(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = FUN_4012c940(param_1);
  if (0x3fff < uVar1) {
    uVar1 = 0x4000;
  }
  uVar2 = FUN_401859c0(param_1);
  uVar3 = uVar1;
  if ((uVar2 != 0) && (uVar3 = FUN_40129ce0(param_1), -1 < (int)uVar3)) {
    if (uVar3 < uVar2) {
      uVar2 = uVar2 - uVar3;
      uVar3 = (uVar1 < uVar2) * uVar1 + (uVar1 >= uVar2) * uVar2;
    }
    else {
      uVar3 = 0xffff8f80;
    }
  }
  return uVar3;
}

