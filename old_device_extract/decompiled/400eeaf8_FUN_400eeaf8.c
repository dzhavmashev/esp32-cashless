// Function : FUN_400eeaf8
// Address  : 0x400eeaf8
// Size     : 152 bytes


int FUN_400eeaf8(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 4) != param_2 + 0x68) {
    iVar1 = param_2;
    for (iVar2 = (*(int *)(param_1 + 4) - (param_2 + 0x68) >> 3) * -0x3b13b13b; 0 < iVar2;
        iVar2 = iVar2 + -1) {
      FUN_400f0d60(iVar1,iVar1 + 0x68);
      *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar1 + 0x78);
      FUN_400f0d60(iVar1 + 0x14,iVar1 + 0x7c);
      FUN_400f0d60(iVar1 + 0x24,iVar1 + 0x8c);
      FUN_400f0d60(iVar1 + 0x34,iVar1 + 0x9c);
      FUN_400f0d60(iVar1 + 0x44,iVar1 + 0xac);
      func_0x4008b3d8(iVar1 + 0x54,iVar1 + 0xbc,5);
      func_0x4008b3d8(iVar1 + 0x5c,iVar1 + 0xc4,5);
      *(undefined1 *)(iVar1 + 100) = *(undefined1 *)(iVar1 + 0xcc);
      *(undefined1 *)(iVar1 + 0x65) = *(undefined1 *)(iVar1 + 0xcd);
      iVar1 = iVar1 + 0x68;
    }
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -0x68;
  FUN_400ee7e0();
  return param_2;
}

