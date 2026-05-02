// Function : FUN_400fbe78
// Address  : 0x400fbe78
// Size     : 371 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400fbe78(undefined1 *param_1,int *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int *piVar7;
  int *piVar8;
  int local_44;
  undefined4 uStack_40;
  byte bStack_3c;
  undefined1 uStack_3b;
  int iStack_28;
  int *piStack_24;
  
  piVar7 = (int *)&DAT_3ffc5708;
  memw();
  memw();
  piStack_24 = _DAT_3ffc5708;
  puVar5 = (undefined1 *)0x102;
  if (param_2 == (int *)0x0) goto LAB_400fbf14;
  *(undefined4 *)(param_1 + 0x40) = 0;
  piVar7 = &local_44;
  *(int **)(param_1 + 0x50) = param_2;
  *(int *)(param_1 + 8) = param_3 << 0xc;
  uStack_3b = 0xff;
  memw();
  memw();
  puVar5 = (undefined1 *)(**(code **)(*param_2 + 0xc))(param_2,param_3 << 0xc,piVar7,0x20);
  uVar3 = 0;
  if (puVar5 != (undefined1 *)0x0) goto LAB_400fbfde;
  if (local_44 == -1) {
    *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
    memw();
    piVar7 = (int *)(*(code *)&LAB_4016ffdf_1)(0x200,&DAT_3f424b88);
    if (piVar7 == (int *)0x0) {
      puVar5 = (undefined1 *)0x101;
      goto LAB_400fbf14;
    }
    piVar4 = piVar7 + 0x80;
    piVar2 = (int *)0x0;
    puVar6 = puVar5;
    goto LAB_400fbee9;
  }
  iVar1 = FUN_400fb0e0(piVar7);
  if (iStack_28 == iVar1) {
    *(int *)(param_1 + 0xc) = local_44;
    *(undefined4 *)(param_1 + 0x10) = uStack_40;
    if (bStack_3c < 0xfe) {
      puVar5 = (undefined1 *)0x1110;
      goto LAB_400fbf14;
    }
    param_1[0x14] = bStack_3c;
    memw();
    memw();
  }
  else {
    local_44 = -0x10;
    memw();
  }
LAB_400fbf52:
  piVar7 = *(int **)(param_1 + 0xc);
  if (piVar7 != (int *)0xfffffffc) {
    if (piVar7 < (int *)0xfffffffd) {
      if (piVar7 != (int *)0xfffffff8) {
LAB_400fbfdc:
        uVar3 = 0xfffffff0;
LAB_400fbfde:
        *(undefined4 *)(param_1 + 0xc) = uVar3;
        memw();
        goto LAB_400fbf14;
      }
    }
    else if (piVar7 != (int *)0xfffffffe) {
      if (piVar7 == (int *)0xffffffff) goto LAB_400fbf14;
      goto LAB_400fbfdc;
    }
  }
  puVar5 = (undefined1 *)FUN_400fbafc(param_1);
LAB_400fbf14:
  do {
    piVar4 = piStack_24;
    piVar2 = _DAT_3ffc5708;
    memw();
    memw();
    if (piStack_24 == _DAT_3ffc5708) {
      return;
    }
    (*(code *)&SUB_40082ec4)();
    piVar8 = piVar7;
    puVar6 = &DAT_3ffc5708;
    param_1 = puVar5;
    do {
      do {
        puVar5 = puVar6;
        puVar6 = puVar5;
        if (*piVar8 != -1) {
LAB_400fbf40:
          if (piVar4 == piVar8) break;
          *(undefined4 *)(param_1 + 0xc) = 0xfffffff0;
LAB_400fbf47:
          memw();
          FUN_4016fffc(piVar7);
          goto LAB_400fbf52;
        }
        if (piVar8[1] != -1) {
          piVar8 = piVar8 + 1;
          goto LAB_400fbf40;
        }
        if (piVar8[2] != -1) {
          piVar8 = piVar8 + 2;
          goto LAB_400fbf40;
        }
        if (piVar8[3] != -1) {
          piVar8 = piVar8 + 3;
          goto LAB_400fbf40;
        }
        piVar8 = piVar8 + 4;
      } while (piVar4 != piVar8);
      piVar2 = piVar2 + 0x80;
      if (piVar2 == (int *)0x1000) goto LAB_400fbf47;
LAB_400fbee9:
      puVar5 = (undefined1 *)
               (**(code **)(**(int **)(param_1 + 0x50) + 0xc))
                         (*(int **)(param_1 + 0x50),
                          (undefined1 *)((int)piVar2 + *(int *)(param_1 + 8)),piVar7,0x200);
      piVar8 = piVar7;
    } while (puVar5 == (undefined1 *)0x0);
    *(undefined4 *)(param_1 + 0xc) = 0;
    memw();
    FUN_4016fffc(piVar7);
  } while( true );
}

