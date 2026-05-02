// Function : FUN_40116154
// Address  : 0x40116154
// Size     : 211 bytes


void FUN_40116154(int param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  undefined1 uVar8;
  undefined4 uStack_28;
  undefined2 uStack_24;
  undefined2 uStack_22;
  
  uStack_28 = 0;
  memw();
  iVar4 = FUN_4010bbc4(0x4a,8,0x280);
  if (iVar4 != 0) {
    puVar5 = *(undefined1 **)(iVar4 + 4);
    if (*(ushort *)(iVar4 + 10) < 8) {
      (*(code *)&SUB_40094c54)("gmp_msg",0x32a,"systems","p_input");
    }
    uStack_28 = *(undefined4 *)(param_1 + 4);
    uVar7 = *(undefined4 *)(param_2 + 4);
    uVar2 = (undefined1)((uint)uVar7 >> 0x10);
    uVar1 = (undefined1)((uint)uVar7 >> 0x18);
    uVar8 = (undefined1)((uint)uVar7 >> 8);
    if (param_3 == 0x16) {
      puVar6 = (undefined1 *)(param_2 + 4);
      puVar5[7] = uVar1;
      puVar5[4] = (char)uVar7;
      puVar5[5] = uVar8;
      puVar5[6] = uVar2;
      *(undefined1 *)(param_2 + 8) = 1;
    }
    else {
      puVar5[4] = (char)uVar7;
      puVar5[5] = uVar8;
      puVar5[6] = uVar2;
      puVar5[7] = uVar1;
      memw();
      puVar6 = &DAT_3ffc647c;
      memw();
    }
    puVar5[1] = 0;
    *puVar5 = (char)param_3;
    puVar5[2] = 0;
    puVar5[3] = 0;
    memw();
    memw();
    uVar3 = FUN_4011dc60(puVar5,8);
    puVar5[2] = (char)uVar3;
    puVar5[3] = (char)((ushort)uVar3 >> 8);
    uStack_24 = 0x494;
    uStack_22 = 0;
    memw();
    memw();
    FUN_40116cc8(iVar4,&uStack_28,puVar6,1,0,2,param_1,&uStack_24,4);
    FUN_4010bb10(iVar4);
  }
  return;
}

