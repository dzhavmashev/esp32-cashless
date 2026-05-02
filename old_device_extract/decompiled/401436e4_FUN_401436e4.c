// Function : FUN_401436e4
// Address  : 0x401436e4
// Size     : 81 bytes


void FUN_401436e4(int param_1,undefined4 param_2,undefined1 param_3)

{
  int iVar1;
  
  FUN_40143560(param_1);
  iVar1 = (*(code *)&SUB_400902a8)();
  if (iVar1 != 0) {
    (*(code *)&SUB_40094c54)("_engine/sha.c",0xd5,"locked\"","se <= 3");
  }
  FUN_401686c0();
  FUN_40143630();
  if (-1 < param_1) {
    if (param_1 < 2) {
      iVar1 = 0x10;
    }
    else if (param_1 < 4) {
      iVar1 = 0x20;
    }
  }
  FUN_401686f8(param_1,param_2,iVar1,param_3);
  FUN_40143640();
  return;
}

