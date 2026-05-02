// Function : FUN_400e8470
// Address  : 0x400e8470
// Size     : 187 bytes


bool FUN_400e8470(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  int local_38 [14];
  
  iVar2 = FUN_40184688(param_2,param_1);
  if (iVar2 == 0) {
    FUN_40184680(param_2,0);
    FUN_400e818c(0x2000,16000);
    FUN_400e8174(0x6000);
    cVar1 = FUN_4010aed0(param_1,local_38,0x400e78a0,param_2);
    if (cVar1 == '\0') {
      if (local_38[0] != 0) {
        FUN_40184680(param_2);
      }
    }
    else if (cVar1 == -5) {
      FUN_400e818c(0x4000,15000);
      FUN_400e8174(0x4000);
    }
    FUN_400e815c(0x2000);
    if (*(int *)(param_2 + 4) == 0) {
      uVar5 = func_0x40085c04();
      uVar3 = FUN_401847ec("02X%02X");
      uVar4 = (*(code *)&SUB_4000cff8)((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),1000,0);
      FUN_4012105c("rt %d\r\n",uVar4,uVar3,0x62f,"ailed\r\n",param_1);
    }
  }
  return *(int *)(param_2 + 4) != 0;
}

