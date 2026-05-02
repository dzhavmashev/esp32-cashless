// Function : FUN_40143560
// Address  : 0x40143560
// Size     : 107 bytes


int FUN_40143560(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int in_SCOMPARE1;
  
  iVar3 = 0;
  if ((param_1 != 0) && (iVar3 = 1, param_1 != 1)) {
    iVar3 = 2;
  }
  piVar4 = (int *)(iVar3 * 4 + 0x3ffc78d4);
  memw();
  iVar1 = *piVar4;
  if (iVar1 == 0) {
    iVar2 = (*(code *)&SUB_4008f990)(1,0,3);
    iVar1 = iVar2;
    if (iVar2 == 0) {
      iVar1 = (*(code *)&SUB_40094c54)("_engine/sha.c",0x72,"t_state",&DAT_3f4230ca);
    }
    (*(code *)&SUB_4008fab8)(iVar1,0,0,0);
    wsr((char)in_SCOMPARE1,0);
    iVar1 = *piVar4;
    if (iVar1 == in_SCOMPARE1) {
      *piVar4 = iVar2;
    }
    if (iVar1 != 0) {
      (*(code *)&SUB_400902d4)(iVar2);
    }
    memw();
    iVar1 = *(int *)(iVar3 * 4 + 0x3ffc78d4);
  }
  return iVar1;
}

