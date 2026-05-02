// Function : FUN_400eb7d8
// Address  : 0x400eb7d8
// Size     : 165 bytes


void FUN_400eb7d8(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_21 [33];
  
  iVar2 = param_1 + 0x68c;
  iVar1 = FUN_40184578(iVar2);
  if (*(char *)(iVar1 + 0x89) == '\0') {
    *(undefined1 *)(param_1 + 0x764) = 0;
    (*(code *)&LAB_40184472_2)(param_1 + 0xb0,4);
    FUN_400eb730(param_1);
    iVar1 = FUN_40184578(iVar2);
    if (*(char *)(iVar1 + 0x88) == '\0') {
      FUN_400eb038(param_1,1);
    }
    if (*(int *)(param_1 + 0x14) != 0) {
      func_0x4008fac0(*(undefined4 *)(param_1 + 0xd0),0,0);
      iVar1 = FUN_40184578(iVar2);
      auStack_21[0] = *(char *)(iVar1 + 0x88) != '\0';
      if (*(int *)(param_1 + 0x14) == 0) {
        FUN_40170584();
      }
      (**(code **)(param_1 + 0x18))(param_1 + 0xc,auStack_21);
      func_0x40090018(*(undefined4 *)(param_1 + 0xd0),0xffffffff);
    }
  }
  else {
    (*(code *)&LAB_40184472_2)(param_1 + 0xb0,7);
    iVar1 = FUN_40184578(iVar2);
    *(undefined1 *)(param_1 + 0x765) = *(undefined1 *)(iVar1 + 0x89);
  }
  return;
}

