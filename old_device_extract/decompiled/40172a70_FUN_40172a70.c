// Function : FUN_40172a70
// Address  : 0x40172a70
// Size     : 875 bytes


/* WARNING: Removing unreachable block (ram,0x40172773) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40172a70(int param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  char *pcVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  int in_stack_00000024;
  undefined4 in_stack_00000028;
  undefined1 in_stack_0000002c;
  int in_stack_00000034;
  int in_stack_00000038;
  undefined4 in_stack_0000003c;
  undefined4 in_stack_00000040;
  int in_stack_0000004c;
  
code_r0x40172a70:
  *(undefined1 *)(param_1 + 0x20) = param_2;
  param_1 = param_5;
LAB_40172708:
  iVar1 = in_stack_0000004c;
  iVar4 = _DAT_3ffc5708;
  memw();
  memw();
  if (in_stack_0000004c == _DAT_3ffc5708) {
    return;
  }
  uVar2 = (*(code *)&SUB_40082ec4)();
  uVar3 = FUN_4011fc40(uVar2,3,0);
  FUN_4011fc40(&DAT_3ffc5708,4,uVar3 | 0x4000);
  uVar2 = *(undefined4 *)(iVar4 + 4);
  (*(code *)&SUB_4008b530)(&stack0x0000003c,0,0x10);
  in_stack_0000003c._1_1_ = 2;
  in_stack_00000040 = uVar2;
  in_stack_0000003c._2_2_ = FUN_40185290(iVar1);
  in_stack_0000002c = 0;
  in_stack_00000034 = *(int *)(param_1 + 0x24) / 1000;
  in_stack_00000038 = (*(int *)(param_1 + 0x24) % 1000) * 1000;
  iVar4 = FUN_401091ec(&DAT_3ffc5708,&stack0x0000003c,0x10);
  if ((iVar4 < 0) && (piVar5 = (int *)FUN_40173a8c(), *piVar5 != 0x77)) {
    uVar10 = (*(code *)&SUB_40085bfc)();
    uVar2 = FUN_401847f4(&DAT_3f424da0);
    FUN_40173a8c();
    puVar6 = (undefined4 *)FUN_40173a8c();
    FUN_401745d0(*puVar6);
    uVar7 = (*(code *)&SUB_4000cff8)((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),1000,0);
    pcVar8 = "ocket\r\n";
    uVar9 = 0xf9;
  }
  else {
    puVar6 = (undefined4 *)0x0;
    if (-1 < *(int *)(param_1 + 0x24)) {
      puVar6 = &stack0x00000034;
    }
    iVar4 = FUN_400fefac(0x3ffc5709,0,&stack0x0000002c,0,puVar6);
    if (iVar4 < 0) {
      uVar10 = (*(code *)&SUB_40085bfc)();
      uVar2 = FUN_401847f4(&DAT_3f424da0);
      FUN_40173a8c();
      puVar6 = (undefined4 *)FUN_40173a8c();
      FUN_401745d0(*puVar6);
      uVar7 = (*(code *)&SUB_4000cff8)((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),1000,0);
      uVar9 = 0x100;
      pcVar8 = " \"%s\"\r\n";
      goto LAB_40172706;
    }
    if (iVar4 == 0) {
      (*(code *)&SUB_40001778)(&DAT_3ffc5708);
      param_1 = 0;
      goto LAB_40172708;
    }
    in_stack_00000028 = 4;
    iVar4 = FUN_401099c4(&DAT_3ffc5708,0xfff,0x1007,&stack0x00000024,&stack0x00000028);
    if (-1 < iVar4) {
      if (in_stack_00000024 != 0) {
        uVar10 = (*(code *)&SUB_40085bfc)();
        uVar2 = FUN_401847f4(&DAT_3f424da0);
        FUN_401745d0(in_stack_00000024);
        uVar7 = (*(code *)&SUB_4000cff8)((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),1000,0);
        uVar9 = 0x113;
        pcVar8 = " \"%s\"\r\n";
        goto LAB_40172706;
      }
      iVar4 = FUN_40109a64(&DAT_3ffc5708,0xfff,0x1005,&stack0x00000034,8);
      if (iVar4 < 0) {
        uVar10 = (*(code *)&SUB_40085bfc)();
        uVar2 = FUN_401847f4(&DAT_3f424da0);
        FUN_40173a8c();
        puVar6 = (undefined4 *)FUN_40173a8c();
        FUN_401745d0(*puVar6);
        uVar7 = (*(code *)&SUB_4000cff8)((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),1000,0);
        pcVar8 = "t: %d\r\n";
        uVar9 = 0x11a;
      }
      else {
        iVar4 = FUN_40109a64(&DAT_3ffc5708,0xfff,0x1006,&stack0x00000034,8);
        if (-1 < iVar4) goto LAB_40172a2a;
        uVar10 = (*(code *)&SUB_40085bfc)();
        uVar2 = FUN_401847f4(&DAT_3f424da0);
        FUN_40173a8c();
        puVar6 = (undefined4 *)FUN_40173a8c();
        FUN_401745d0(*puVar6);
        uVar7 = (*(code *)&SUB_4000cff8)((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),1000,0);
        uVar9 = 0x11b;
        pcVar8 = " \"%s\"\r\n";
      }
      FUN_4012105c(pcVar8,uVar7,uVar2,uVar9,"tOption",&DAT_3ffc5708);
      param_1 = 0;
      goto LAB_40172708;
    }
    uVar10 = (*(code *)&SUB_40085bfc)();
    uVar2 = FUN_401847f4(&DAT_3f424da0);
    FUN_40173a8c();
    puVar6 = (undefined4 *)FUN_40173a8c();
    FUN_401745d0(*puVar6);
    uVar7 = (*(code *)&SUB_4000cff8)((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),1000,0);
    uVar9 = 0x10d;
    pcVar8 = " \"%s\"\r\n";
  }
LAB_40172706:
  FUN_4012105c(pcVar8,uVar7,uVar2,uVar9,"tOption",&DAT_3ffc5708);
  (*(code *)&SUB_40001778)(&DAT_3ffc5708);
  param_1 = 0;
  goto LAB_40172708;
LAB_40172a2a:
  uVar3 = FUN_4011fc40(&DAT_3ffc5708,3,0);
  FUN_4011fc40(&DAT_3ffc5708,4,uVar3 & 0xffffbfff);
  puVar6 = (undefined4 *)FUN_40170220(4);
  *puVar6 = &DAT_3ffc5708;
  FUN_401725d8(param_1 + 0x10,puVar6);
  puVar6 = (undefined4 *)FUN_40170220(0x18);
  *puVar6 = 0x59c;
  puVar6[1] = 0;
  puVar6[2] = 0;
  puVar6[3] = 0;
  *(undefined1 *)(puVar6 + 5) = 0;
  puVar6[4] = &DAT_3ffc5708;
  FUN_40172640(param_1 + 0x18,puVar6);
  param_2 = 1;
  param_5 = 1;
  goto code_r0x40172a70;
}

