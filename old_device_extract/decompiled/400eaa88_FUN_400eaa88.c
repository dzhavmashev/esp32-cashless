// Function : FUN_400eaa88
// Address  : 0x400eaa88
// Size     : 85 bytes


uint FUN_400eaa88(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = FUN_400f1a9c();
  while( true ) {
    uVar2 = FUN_4012a7e4(param_1 + 8,param_2,param_3);
    if (0 < (int)uVar2) {
      return uVar2;
    }
    iVar3 = FUN_400f1a9c();
    if (*(uint *)(param_1 + 0x890) < (uint)(iVar3 - iVar1)) break;
    if (((uVar2 & 0xffffff7f) != 0xffff9700) && (uVar2 != 0)) {
      uVar2 = FUN_400e9fc8(uVar2,"o: %s\r\n",0x17e);
      return uVar2;
    }
    func_0x4009183c(2);
  }
  return 0xffffffff;
}

