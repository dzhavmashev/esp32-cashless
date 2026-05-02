// Function : FUN_400eb9cc
// Address  : 0x400eb9cc
// Size     : 483 bytes


void FUN_400eb9cc(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  code *pcVar5;
  undefined **ppuVar6;
  undefined *puStack_28;
  undefined4 uStack_24;
  
  iVar3 = param_1 + 0xb0;
  iVar1 = FUN_40184464(iVar3);
  if (iVar1 == 4) {
LAB_400ebb32:
    iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x14))();
    if (iVar1 == 0) {
LAB_400ebb1c:
      (*(code *)&LAB_40184472_2)(iVar3,7);
      *(undefined1 *)(param_1 + 0x765) = 7;
      goto LAB_400eb9f1;
    }
LAB_400ebb3e:
    func_0x40090018(*(undefined4 *)(param_1 + 0xd0),0xffffffff);
LAB_400ebb46:
    FUN_400eb7c0(param_1);
    FUN_400eb880(param_1);
    FUN_400eb450(param_1);
    FUN_400eab48(param_1);
  }
  else {
    if (4 < iVar1) {
      if (iVar1 == 6) goto LAB_400ebb32;
      if (5 < iVar1) {
        if (iVar1 != 7) {
          if ((iVar1 == 8) && (iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x18))(), iVar1 != 0))
          {
            func_0x40090018(*(undefined4 *)(param_1 + 0xd0),0xffffffff);
            FUN_400eb038(param_1,0);
            func_0x4008fac0(*(undefined4 *)(param_1 + 0xd0),0,0);
            *(undefined4 *)(param_1 + 0x688) = 0;
            (*(code *)&LAB_40184472_2)(iVar3);
            if (*(int *)(param_1 + 0x24) != 0) {
              puStack_28 = (undefined *)CONCAT31(puStack_28._1_3_,*(undefined1 *)(param_1 + 0x765));
              (**(code **)(param_1 + 0x28))(param_1 + 0x1c,&puStack_28);
            }
          }
          goto LAB_400eb9f1;
        }
        (**(code **)(**(int **)(param_1 + 8) + 0x10))();
        uVar2 = 8;
LAB_400ebafd:
        (*(code *)&LAB_40184472_2)(iVar3,uVar2);
        goto LAB_400eb9f1;
      }
      func_0x40090018(*(undefined4 *)(param_1 + 0xd0),0xffffffff);
      if (*(int *)(param_1 + 0x678) == 0) {
        iVar1 = FUN_400eb3c0(param_1,&DAT_3f409946);
        if (iVar1 == 0) {
          func_0x4008fac0(*(undefined4 *)(param_1 + 0xd0),0,0,0);
          (*(code *)&LAB_4018443f_1)(param_1,0,1);
          goto LAB_400ebb3e;
        }
        (*(code *)&LAB_40184472_2)(iVar3,6);
      }
      goto LAB_400ebb46;
    }
    if (iVar1 == 1) {
      puVar4 = (undefined4 *)**(int **)(param_1 + 8);
      if (*(char *)(param_1 + 0x8e) == '\0') {
        pcVar5 = (code *)puVar4[1];
        ppuVar6 = *(undefined ***)(param_1 + 0x88);
      }
      else {
        pcVar5 = (code *)*puVar4;
        puStack_28 = &DAT_3f40a508;
        uStack_24 = *(undefined4 *)(param_1 + 0x84);
        ppuVar6 = &puStack_28;
      }
      iVar1 = (*pcVar5)(*(int **)(param_1 + 8),ppuVar6,*(undefined2 *)(param_1 + 0x8c));
      if (iVar1 != 0) {
        (*(code *)&LAB_40184472_2)(iVar3,2);
LAB_400ebadb:
        iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x14))();
        if (iVar1 != 0) {
          FUN_400ec5e0(param_1 + 0x68c);
          uVar2 = FUN_400f1a9c();
          *(undefined4 *)(param_1 + 0x760) = uVar2;
          *(undefined4 *)(param_1 + 0x75c) = uVar2;
          uVar2 = 3;
          goto LAB_400ebafd;
        }
        iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x18))();
        if (iVar1 == 0) goto LAB_400eb9f1;
      }
      goto LAB_400ebb1c;
    }
    if (iVar1 < 2) {
      if ((iVar1 == 0) && (*(int *)(param_1 + 4) == 1)) {
        func_0x40091530(*(undefined4 *)(param_1 + 0xd4));
      }
      goto LAB_400eb9f1;
    }
    if (iVar1 == 2) goto LAB_400ebadb;
    if (iVar1 != 3) goto LAB_400eb9f1;
    iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x14))();
    if (iVar1 == 0) goto LAB_400ebb1c;
    func_0x40090018(*(undefined4 *)(param_1 + 0xd0),0xffffffff);
    FUN_400eaaf0(param_1);
    FUN_400eb880(param_1);
    FUN_400eb450(param_1);
  }
  func_0x4008fac0(*(undefined4 *)(param_1 + 0xd0),0,0);
LAB_400eb9f1:
  func_0x4009183c(1);
  return;
}

