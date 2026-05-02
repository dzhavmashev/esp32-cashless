// Function : FUN_400f77c8
// Address  : 0x400f77c8
// Size     : 406 bytes


undefined4 FUN_400f77c8(int param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  char *pcVar9;
  undefined4 uVar10;
  int aiStack_24 [9];
  
  if (param_1 < 3) {
    iVar6 = param_1 * 4;
    iVar5 = *(int *)(iVar6 + 0x3ffc5588);
    if (iVar5 != 0) {
      (*(code *)&SUB_40090010)(*(undefined4 *)(iVar5 + 0xe0),0xffffffff);
      iVar7 = param_1 * 0x10;
      iVar4 = iVar7 + 0x3ffbdc7c;
      (*(code *)&SUB_40092a98)(iVar4,0xffffffff);
      memw();
      memw();
      *(uint *)(*(int *)(iVar7 + 0x3ffbdc78) + 0xc) =
           *(uint *)(*(int *)(iVar7 + 0x3ffbdc78) + 0xc) & 0xfffffefe;
      do {
        memw();
        (*(code *)&SUB_40092bec)(iVar4);
        do {
          iVar3 = (*(code *)&SUB_4008ed14)(*(undefined4 *)(iVar5 + 0xd8),aiStack_24,0);
          if (iVar3 == 0) {
            memw();
            (*(code *)&SUB_40092a98)();
            iVar6 = *(int *)(iVar6 + 0x3ffc5588);
            bVar1 = *(int *)(iVar6 + 0x14) != 0;
            if (bVar1) {
              *(undefined4 *)(iVar6 + 0x14) = 0;
            }
            *(undefined1 *)(iVar6 + 0x1c) = 0;
            memw();
            memw();
            (*(code *)&SUB_40092bec)(iVar4);
            if (bVar1) {
              uVar2 = (*(code *)&SUB_40094b80)();
              FUN_4012113c(1,"th","s NULL\n",uVar2,"th");
            }
            FUN_400fe324(iVar7 + 0x3ffbdc78);
            FUN_400f65f0(param_1);
            (*(code *)&SUB_4008fab8)(*(undefined4 *)(iVar5 + 0xe0),0,0);
            return 0;
          }
          (*(code *)&SUB_40092a98)(iVar4,0xffffffff);
          piVar8 = (int *)(iVar6 + 0x3ffc5588);
          *(int *)(*piVar8 + 0x14) = *(int *)(*piVar8 + 0x14) - aiStack_24[0];
          memw();
          FUN_400f5c34(param_1);
          (*(code *)&SUB_40092bec)(iVar4);
          (*(code *)&SUB_4008edec)(*(undefined4 *)(iVar5 + 0xd8),iVar3);
          iVar3 = *piVar8;
        } while ((*(char *)(iVar3 + 0x1c) == '\0') ||
                (iVar3 = (*(code *)&SUB_4008eb98)
                                   (*(undefined4 *)(iVar3 + 0xd8),iVar3 + 0x1d,
                                    *(undefined1 *)(iVar3 + 0x9d),1), iVar3 != 1));
        (*(code *)&SUB_40092a98)(iVar4,0xffffffff);
        iVar3 = *piVar8;
        *(uint *)(iVar3 + 0x14) = *(int *)(iVar3 + 0x14) + (uint)*(byte *)(iVar3 + 0x9d);
        *(undefined1 *)(iVar3 + 0x1c) = 0;
        memw();
        memw();
      } while( true );
    }
    uVar2 = (*(code *)&SUB_40094b80)();
    uVar10 = 0x564;
    pcVar9 = " error\n";
    memw();
  }
  else {
    uVar2 = (*(code *)&SUB_40094b80)();
    pcVar9 = "_select";
    uVar10 = 0x563;
  }
  memw();
  FUN_4012113c(1,"th",pcVar9,uVar2,"th","install",uVar10);
  return 0xffffffff;
}

