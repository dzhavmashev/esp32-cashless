// Function : FUN_401714e4
// Address  : 0x401714e4
// Size     : 66 bytes


int FUN_401714e4(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint local_30;
  uint auStack_2c [11];
  
  uVar3 = *(uint *)(param_1 + 0x10) >> 3 & 0xff;
  uVar1 = FUN_401713c4(uVar3,param_1);
  FUN_40171410(uVar3,uVar1,param_2 + 8,auStack_2c);
  FUN_40171410(*(uint *)(param_1 + 0x10) >> 3 & 0xff,uVar1,param_3 + 8,&local_30);
  iVar2 = 1;
  if (auStack_2c[0] <= local_30) {
    iVar2 = -(uint)(auStack_2c[0] < local_30);
  }
  return iVar2;
}

