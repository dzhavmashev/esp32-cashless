// Function : FUN_400fe75c
// Address  : 0x400fe75c
// Size     : 235 bytes


int FUN_400fe75c(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  
  iVar5 = 0;
  iVar4 = 0;
  param_1 = param_1 + 0x14;
  while (iVar5 < param_2) {
    if (*(char *)(param_1 + -0x14) != '\0') {
      uVar2 = 0;
      iVar6 = 0x3ffbdd4c;
      do {
        if (*(char *)(iVar6 + 1) == iVar5) {
          uVar1 = *(undefined1 *)(iVar6 + 2);
          if (param_3 != 0) {
            memw();
            iVar3 = (*(code *)&LAB_40184def_1)(uVar1,param_1 + -0x10);
            if (iVar3 != 0) {
              iVar4 = iVar4 + 1;
              puVar7 = (uint *)(param_3 + (uVar2 >> 5) * 4);
              *puVar7 = *puVar7 | 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
            }
          }
          if (param_4 != 0) {
            memw();
            iVar3 = (*(code *)&LAB_40184def_1)(uVar1,param_1 + -8);
            if (iVar3 != 0) {
              iVar4 = iVar4 + 1;
              puVar7 = (uint *)(param_4 + (uVar2 >> 5) * 4);
              *puVar7 = *puVar7 | 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
            }
          }
          if (param_5 != 0) {
            memw();
            iVar3 = (*(code *)&LAB_40184def_1)(uVar1,param_1);
            if (iVar3 != 0) {
              puVar7 = (uint *)(param_5 + (uVar2 >> 5) * 4);
              iVar4 = iVar4 + 1;
              *puVar7 = *puVar7 | 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
            }
          }
        }
        uVar2 = uVar2 + 1;
        iVar6 = iVar6 + 3;
      } while (uVar2 != 0x40);
    }
    iVar5 = iVar5 + 1;
    param_1 = param_1 + 0x1c;
    memw();
  }
  memw();
  return iVar4;
}

