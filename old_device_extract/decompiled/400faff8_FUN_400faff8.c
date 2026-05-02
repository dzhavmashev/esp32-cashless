// Function : FUN_400faff8
// Address  : 0x400faff8
// Size     : 103 bytes


undefined4 FUN_400faff8(int *param_1,uint param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  iVar3 = *param_1;
  do {
    if (iVar3 == 0) {
      return 0;
    }
    iVar5 = 0;
    bVar2 = false;
    iVar4 = *(int *)(iVar3 + 8);
    bVar1 = false;
    while (iVar4 != iVar5) {
      iVar6 = iVar3 + iVar5 * 4;
      uVar7 = (uint)*(byte *)(iVar6 + 0xc);
      if (uVar7 == param_2) {
        bVar2 = true;
        *(undefined1 *)(iVar6 + 0xc) = 0xff;
        memw();
LAB_400fb026:
        if (bVar1) goto LAB_400fb035;
      }
      else {
        if (uVar7 == 0xff) goto LAB_400fb026;
        bVar1 = true;
LAB_400fb035:
        if (bVar2) {
          return 1;
        }
      }
      iVar5 = iVar5 + 1;
      memw();
    }
    iVar4 = *(int *)(iVar3 + 4);
    if (!bVar1) {
      (*(code *)&LAB_401849ef_1)(param_1,iVar3);
      (*(code *)&SUB_40094d80)(iVar3);
    }
    iVar3 = iVar4;
    if (bVar2) {
      return 1;
    }
  } while( true );
}

