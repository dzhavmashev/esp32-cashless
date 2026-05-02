// Function : FUN_40106dd8
// Address  : 0x40106dd8
// Size     : 140 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40106dd8(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = 0;
  if (DAT_3ffc589c == '\0') {
    FUN_401003d4();
    FUN_40145308();
    FUN_401474f8(1);
    (*(code *)&SUB_40086f00)();
    iVar1 = FUN_40146608(param_1);
    if (iVar1 == 0) {
      FUN_40123394();
      _DAT_3ffc5898 = 0x4018b178;
      memw();
      iVar1 = FUN_40123aa8();
      if (iVar1 == 0) {
        DAT_3ffc589c = '\x01';
        memw();
        goto LAB_40106e60;
      }
      uVar2 = (*(code *)&SUB_40094b80)();
      FUN_4012113c(1,"k fail\n",&DAT_3f40f3db,uVar2,"k fail\n",iVar1);
    }
    iVar3 = FUN_40106d18();
    if (iVar3 != 0) {
      uVar2 = (*(code *)&SUB_40094b80)();
      FUN_4012113c(1,"k fail\n","(0x%x)\n",uVar2,"k fail\n",iVar3);
    }
  }
LAB_40106e60:
  memw();
  return iVar1;
}

