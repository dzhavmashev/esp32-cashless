// Function : FUN_4015fa60
// Address  : 0x4015fa60
// Size     : 80 bytes


undefined4
FUN_4015fa60(undefined1 *param_1,uint *param_2,uint *param_3,undefined4 param_4,undefined1 param_5,
            undefined4 param_6,byte param_7)

{
  undefined1 local_40;
  byte bStack_3f;
  byte bStack_3e;
  undefined1 auStack_3d [13];
  uint uStack_30;
  
  uStack_30 = (uint)param_7;
  memw();
  (*(code *)&SUB_4008b530)(&local_40,0,9);
  FUN_401663fc(param_5,param_6,uStack_30,&local_40);
  *param_1 = local_40;
  memw();
  *param_2 = (uint)bStack_3f;
  *param_3 = (uint)bStack_3e;
  memw();
  (*(code *)&SUB_4008b3d0)(param_4,auStack_3d,6);
  return 0;
}

