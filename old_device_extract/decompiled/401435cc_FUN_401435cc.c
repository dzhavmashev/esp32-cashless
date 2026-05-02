// Function : FUN_401435cc
// Address  : 0x401435cc
// Size     : 98 bytes


undefined4 FUN_401435cc(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_40143560(param_1);
  iVar2 = (*(code *)&SUB_40090010)(uVar1,param_2);
  uVar1 = 0;
  if (iVar2 != 0) {
    (*(code *)&SUB_40092a98)(0x3ffbf7b4,0xffffffff);
    if (DAT_3ffc78d0 == 0) {
      FUN_400f552c(0x1f);
    }
    DAT_3ffc78d0 = DAT_3ffc78d0 + 1;
    memw();
    if (3 < DAT_3ffc78d0) {
      memw();
      (*(code *)&SUB_40094c54)("_engine/sha.c",0xa0,"e_state","e/sha.c");
    }
    (*(code *)&SUB_40092bec)(0x3ffbf7b4);
    uVar1 = 1;
  }
  return uVar1;
}

