// Function : FUN_400faf84
// Address  : 0x400faf84
// Size     : 66 bytes


uint FUN_400faf84(int *param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = FUN_400fc5a0(param_3);
  iVar3 = *param_1;
  do {
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    for (iVar4 = 0; *(int *)(iVar3 + 8) != iVar4; iVar4 = iVar4 + 1) {
      iVar5 = iVar3 + iVar4 * 4;
      uVar2 = (uint)*(byte *)(iVar5 + 0xc);
      if (((param_2 <= uVar2) && (*(uint *)(iVar5 + 0xc) >> 8 == (uVar1 & 0xffffff))) &&
         (uVar2 != 0xff)) {
        return uVar2;
      }
    }
    iVar3 = *(int *)(iVar3 + 4);
  } while( true );
}

