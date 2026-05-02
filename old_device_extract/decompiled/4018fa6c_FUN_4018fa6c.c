// Function : FUN_4018fa6c
// Address  : 0x4018fa6c
// Size     : 262 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018fa6c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  char cVar5;
  byte bVar6;
  
  iVar2 = 0;
  if (param_1 != 0) {
    iVar2 = 2;
  }
  cVar5 = '\x02';
  if (param_1 != 0) {
    cVar5 = '\x01';
  }
  iVar4 = 3;
  if (param_1 == 0) {
    iVar4 = 1;
  }
  uVar1 = 0x71;
  if (param_1 != 0) {
    uVar1 = 0x31;
  }
  cVar3 = '\x05';
  if (param_1 == 0) {
    cVar3 = '\n';
  }
  (**(code **)(_DAT_3ffc7e64 + 0xa0))(0x67,1,3,(&DAT_3ffca51c)[iVar2] - cVar5);
  (**(code **)(_DAT_3ffc7e64 + 0xa0))(0x67,1,4,(&DAT_3ffca51c)[iVar2]);
  (**(code **)(_DAT_3ffc7e64 + 0xa0))(0x67,1,10,0x10);
  if (param_1 == 0) {
    (**(code **)(_DAT_3ffc7e64 + 0xa0))(0x67,1,1,(&DAT_3ffca51c)[iVar4] + 10 | 0x80);
    bVar6 = (&DAT_3ffca51c)[iVar4] + 10;
  }
  else {
    (**(code **)(_DAT_3ffc7e64 + 0xa0))(0x67,1,1,((&DAT_3ffca51c)[iVar4] - cVar3) - 4U | 0x80);
    bVar6 = (&DAT_3ffca51c)[iVar4] - 4;
  }
  (**(code **)(_DAT_3ffc7e64 + 0xa0))(0x67,1,2,bVar6 | 0x80);
  (**(code **)(_DAT_3ffc7e64 + 0xa0))(0x67,1,9,uVar1);
  return;
}

