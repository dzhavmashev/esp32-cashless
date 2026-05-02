// Function : FUN_40127f54
// Address  : 0x40127f54
// Size     : 314 bytes


undefined4 FUN_40127f54(int param_1,undefined4 param_2,int param_3,int param_4)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (*(int *)(param_1 + 0x48) != 0) {
    FUN_40125ffc(param_2,*(undefined2 *)(param_1 + 0x3c));
    if (((*(byte *)(param_1 + 0x50) & 1) == 0) && (param_3 != 0)) {
      FUN_40127190(param_2,param_3);
    }
    uVar2 = FUN_40185088(param_2,*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x44));
    uVar5 = *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x44);
    iVar3 = FUN_40128a90(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x20),uVar2,uVar5,uVar5);
    if (-1 < iVar3) {
      iVar3 = *(int *)(*(int *)(param_1 + 0x48) + 0x44);
      if (*(int *)(*(int *)(param_1 + 0x48) + 0x40) == 0) {
        uVar2 = FUN_40185088(param_2,iVar3);
        uVar5 = *(undefined4 *)(*(int *)(param_1 + 0x48) + 0x44);
        iVar3 = FUN_40128a90(*(undefined4 *)(*(int *)(param_1 + 0x48) + 0x24),uVar2,uVar5,uVar5);
      }
      else {
        iVar3 = FUN_40185088(param_2,iVar3 << 1);
        iVar4 = *(int *)(param_1 + 0x48);
        iVar3 = FUN_40128d98(*(undefined4 *)(iVar4 + 0x40),*(undefined4 *)(iVar4 + 0x28),iVar3,
                             iVar3 + *(int *)(iVar4 + 0x44));
      }
      if (-1 < iVar3) {
        if (param_4 != 0) {
          FUN_4012601c(param_2,0xff);
          cVar1 = (*(code *)&SUB_4008c01c)(param_4);
          FUN_4012601c(param_2,cVar1 + '\x01');
          FUN_4012601c(param_2,0x21);
          uVar2 = (*(code *)&SUB_4008c01c)(param_4);
          FUN_40127178(param_2,param_4,uVar2);
        }
        if ((*(byte *)(param_1 + 0x50) & 1) == 0) {
          return 0;
        }
        if (*(int *)(*(int *)(param_1 + 0x48) + 100) != 0) {
          FUN_4012601c(param_2,0xff);
          FUN_4012601c(param_2,*(int *)(*(int *)(*(int *)(param_1 + 0x48) + 100) + 4) + 1U & 0xff);
          FUN_4012601c(param_2,0x5c);
          FUN_40127190(param_2,*(undefined4 *)(*(int *)(param_1 + 0x48) + 100));
        }
        if (((*(byte *)(param_1 + 0x50) & 1) != 0) && (param_3 != 0)) {
          FUN_4012601c(param_2,0xff);
          FUN_4012601c(param_2,*(int *)(param_3 + 4) + 1U & 0xff);
          FUN_4012601c(param_2,0x5d);
          FUN_40127190(param_2,param_3);
        }
        return 0;
      }
    }
  }
  return 0xffffffff;
}

