// Function : FUN_40173a9c
// Address  : 0x40173a9c
// Size     : 202 bytes


int FUN_40173a9c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_30;
  undefined4 local_2c [11];
  
  uVar1 = FUN_4017bf3c(param_1,param_3,local_2c);
  if ((uVar1 != 0) && (iVar2 = (*(code *)&SUB_4008a8e8)(param_1), iVar2 != 0)) {
    iVar3 = FUN_400feb7c(param_1,param_2,local_2c[0],0x1b6);
    if (-1 < iVar3) {
      FUN_4018560c(1,&local_30);
      if (((*(uint *)(iVar2 + 100) & 1) == 0) && ((*(ushort *)(iVar2 + 0xc) & 0x200) == 0)) {
        (*(code *)&SUB_40086504)(*(undefined4 *)(iVar2 + 0x58));
      }
      *(short *)(iVar2 + 0xe) = (short)iVar3;
      *(short *)(iVar2 + 0xc) = (short)uVar1;
      *(undefined4 *)(iVar2 + 0x24) = 0x4008bce8;
      *(int *)(iVar2 + 0x20) = iVar2;
      *(undefined4 *)(iVar2 + 0x28) = 0x4008bd24;
      *(undefined4 *)(iVar2 + 0x2c) = 0x4008bd5c;
      *(undefined4 *)(iVar2 + 0x30) = 0x4008bd94;
      if ((uVar1 & 0x100) != 0) {
        FUN_40173b7c(param_1,iVar2,0,2);
      }
      if (((*(uint *)(iVar2 + 100) & 1) == 0) && ((*(ushort *)(iVar2 + 0xc) & 0x200) == 0)) {
        (*(code *)&SUB_40086534)(*(undefined4 *)(iVar2 + 0x58));
      }
      FUN_4018560c(local_30,&local_30);
      return iVar2;
    }
    FUN_4018560c(1,&local_30);
    (*(code *)&SUB_4008a860)();
    *(undefined2 *)(iVar2 + 0xc) = 0;
    (*(code *)&SUB_400864d8)(*(undefined4 *)(iVar2 + 0x58));
    (*(code *)&SUB_4008a86c)();
    FUN_4018560c(local_30,&local_30);
  }
  return 0;
}

