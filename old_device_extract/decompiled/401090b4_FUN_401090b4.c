// Function : FUN_401090b4
// Address  : 0x401090b4
// Size     : 310 bytes


undefined4 FUN_401090b4(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  bool bVar5;
  int *piVar6;
  undefined4 uVar7;
  int local_50 [4];
  undefined1 uStack_40;
  undefined1 uStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  undefined1 uStack_28;
  undefined1 uStack_24;
  
  piVar2 = (int *)FUN_40108224(param_1);
  if (piVar2 == (int *)0x0) {
LAB_401091c5:
    param_1 = 0xffffffff;
  }
  else {
    if ((uint *)*piVar2 == (uint *)0x0) {
      bVar5 = false;
      if (piVar2[1] == 0) goto LAB_401090da;
      (*(code *)&SUB_40094c54)("!= NULL",0x350,"ecv_tcp","f index");
    }
    else {
      bVar5 = (*(uint *)*piVar2 & 0xf0) == 0x10;
LAB_401090da:
      puVar3 = (undefined4 *)FUN_40108224(param_1);
      if (puVar3 != (undefined4 *)0x0) {
        piVar6 = (int *)&DAT_3ffc5c08;
        do {
          if (puVar3 == (undefined4 *)*piVar6) {
            local_50[0] = piVar6[2];
            iStack_38 = piVar6[1];
            uStack_3c = 0;
            uStack_24 = 0;
            memw();
            uVar7 = *puVar3;
            *piVar6 = 0;
            piVar6[1] = 0;
            piVar6[2] = 0;
            local_50[3] = 0;
            local_50[2] = 0;
            local_50[1] = 0;
            uStack_40 = 0;
            iStack_2c = 0;
            iStack_30 = 0;
            iStack_34 = 0;
            uStack_28 = 0;
            memw();
            memw();
            FUN_4011c5a0(uVar7,local_50,&iStack_38,1);
          }
          piVar6 = piVar6 + 3;
        } while (piVar6 != (int *)&DAT_3ffc5cc8);
        FUN_40108194(puVar3);
      }
      puVar3 = (undefined4 *)FUN_40108224(param_1);
      if (puVar3 != (undefined4 *)0x0) {
        piVar6 = (int *)&DAT_3ffc5a48;
        do {
          if (puVar3 == (undefined4 *)*piVar6) {
            iStack_38 = piVar6[2];
            iStack_34 = piVar6[3];
            iStack_30 = piVar6[4];
            iStack_2c = piVar6[5];
            uStack_28 = (undefined1)piVar6[6];
            uStack_24 = 6;
            memw();
            iVar4 = piVar6[1];
            *(undefined1 *)(piVar6 + 6) = 0;
            *(undefined1 *)(piVar6 + 1) = 0;
            memw();
            uVar7 = *puVar3;
            *piVar6 = 0;
            piVar6[2] = 0;
            piVar6[3] = 0;
            piVar6[4] = 0;
            piVar6[5] = 0;
            memw();
            FUN_4011c5cc(uVar7,&iStack_38,(char)iVar4,1);
          }
          piVar6 = piVar6 + 7;
        } while (piVar6 != (int *)&DAT_3ffc5c08);
        FUN_40108194(puVar3);
      }
      cVar1 = FUN_4011c0b8(*piVar2);
      param_1 = 0;
      if (cVar1 != '\0') {
        iVar4 = FUN_4011d9e4((int)cVar1);
        if (iVar4 != 0) {
          piVar6 = (int *)FUN_40173a8c();
          *piVar6 = iVar4;
        }
        memw();
        FUN_40108194(piVar2);
        goto LAB_401091c5;
      }
    }
    FUN_40108044(piVar2,bVar5);
  }
  return param_1;
}

