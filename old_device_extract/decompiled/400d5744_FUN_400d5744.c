// Function : FUN_400d5744
// Address  : 0x400d5744
// Size     : 343 bytes


undefined4 FUN_400d5744(int *param_1,int param_2)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  byte bVar4;
  undefined4 uVar5;
  char *pcVar6;
  
  bVar4 = *(byte *)(param_1 + 2) & 0x7f;
  if (bVar4 == 6) {
    pcVar6 = "\fn\nr\rt\t";
    if ((char)*param_1 == '\0') {
      pcVar6 = "t\t";
    }
LAB_400d58a0:
    FUN_400d4ac0(param_2,pcVar6);
  }
  else {
    if (bVar4 < 7) {
      if (bVar4 < 2) goto LAB_400d5780;
      if (bVar4 < 4) {
        FUN_400d4aa0(param_2,*param_1,param_1[1]);
        goto LAB_400d57c8;
      }
      puVar1 = (undefined1 *)*param_1;
      iVar2 = param_1[1];
      FUN_400d556c(param_2,0x22);
      puVar3 = puVar1 + iVar2;
      for (; puVar3 != puVar1; puVar1 = puVar1 + 1) {
        FUN_400d5584(param_2,*puVar1);
      }
      uVar5 = 0x22;
    }
    else {
      if (bVar4 == 0xc) {
        FUN_400d55c0(param_2);
        goto LAB_400d57c8;
      }
      if (bVar4 < 0xd) {
        if (bVar4 != 8) {
          if (bVar4 != 10) goto LAB_400d5780;
          if (param_1[1] < 0) {
            FUN_400d556c(param_2,0x2d);
          }
        }
        FUN_400d4ad8(param_2);
        goto LAB_400d57c8;
      }
      if (bVar4 == 0x20) {
        FUN_400d556c(param_2,0x7b);
        iVar2 = *param_1;
        while (iVar2 != 0) {
          pcVar6 = *(char **)(iVar2 + 0xc);
          FUN_400d556c(param_2,0x22);
          for (; *pcVar6 != '\0'; pcVar6 = pcVar6 + 1) {
            FUN_400d5584(param_2);
          }
          FUN_400d556c(param_2,0x22);
          FUN_400d556c(param_2,0x3a);
          FUN_400d5744(iVar2,param_2);
          iVar2 = (*(code *)&LAB_40183a9a_2)(iVar2);
          if (iVar2 == 0) break;
          FUN_400d556c(param_2,0x2c);
        }
        uVar5 = 0x7d;
      }
      else {
        if (bVar4 != 0x40) {
LAB_400d5780:
          pcVar6 = "PIO ISR null";
          goto LAB_400d58a0;
        }
        FUN_400d556c(param_2,0x5b);
        iVar2 = *param_1;
        while (iVar2 != 0) {
          FUN_400d5744(iVar2,param_2);
          iVar2 = (*(code *)&LAB_40183a9a_2)(iVar2);
          if (iVar2 == 0) break;
          FUN_400d556c(param_2,0x2c);
        }
        uVar5 = 0x5d;
      }
    }
    FUN_400d556c(param_2,uVar5);
  }
LAB_400d57c8:
  return *(undefined4 *)(param_2 + 0x28);
}

