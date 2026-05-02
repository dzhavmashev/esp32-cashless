// Function : FUN_400eb168
// Address  : 0x400eb168
// Size     : 278 bytes


undefined4 FUN_400eb168(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  char cStack_29;
  undefined4 *puStack_28;
  undefined4 uStack_24;
  
  iVar1 = FUN_40184464(param_1 + 0xb0);
  if (iVar1 != 0) {
    return 0;
  }
  func_0x40090018(*(undefined4 *)(param_1 + 0xd0),0xffffffff);
  uVar2 = *(uint *)(param_1 + 0x90);
  cStack_29 = '\0';
  puStack_28 = (undefined4 *)(*(code *)&LAB_4016fa0f_1)(0x30,&DAT_3f424b88);
  if (puStack_28 != (undefined4 *)0x0) {
    *puStack_28 = 0;
    FUN_400ebc7c(puStack_28 + 1,&cStack_29,*(undefined1 *)(param_1 + 0x94),
                 *(undefined4 *)(param_1 + 0x98),*(undefined4 *)(param_1 + 0x9c),
                 *(undefined4 *)(param_1 + 0xa0),*(undefined1 *)(param_1 + 0xab),
                 *(undefined1 *)(param_1 + 0xaa),*(undefined4 *)(param_1 + 0xa4),
                 *(undefined2 *)(param_1 + 0xa8),uVar2 / 1000 & 0xffff,
                 *(undefined4 *)(param_1 + 0x7c));
    puStack_28[0xb] = 0;
    if (*(int *)(param_1 + 0x678) == 0) {
      *(undefined4 **)(param_1 + 0x67c) = puStack_28;
    }
    else {
      puStack_28[0xb] = *(int *)(param_1 + 0x678);
    }
    *(undefined4 **)(param_1 + 0x678) = puStack_28;
    *(undefined4 **)(param_1 + 0x680) = puStack_28;
    *(undefined4 *)(param_1 + 0x684) = 0;
  }
  uStack_24 = 0;
  if (puStack_28 != (undefined4 *)0x0) {
    if (cStack_29 == '\0') {
      (*(code *)&LAB_40184472_2)(param_1 + 0xb0,1);
      if (*(int *)(param_1 + 4) == 1) {
        func_0x40090a5c(*(undefined4 *)(param_1 + 0xd4));
        uVar3 = 1;
      }
      else {
        uVar3 = 1;
      }
      goto LAB_400eb263;
    }
    FUN_400dad2c(param_1 + 0x678,&puStack_28);
  }
  func_0x4008fac0(*(undefined4 *)(param_1 + 0xd0),0,0);
  (*(code *)&LAB_4018443f_1)(param_1,0,1);
  func_0x40090018(*(undefined4 *)(param_1 + 0xd0),0xffffffff);
  uVar3 = 0;
LAB_400eb263:
  func_0x4008fac0(*(undefined4 *)(param_1 + 0xd0),0,0);
  return uVar3;
}

