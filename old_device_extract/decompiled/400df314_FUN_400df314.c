// Function : FUN_400df314
// Address  : 0x400df314
// Size     : 92 bytes


undefined4 FUN_400df314(int param_1,ushort param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar2 = (*(code *)&SUB_4000c938)(*(undefined1 *)(param_1 + 0x3d));
  uVar2 = (*(code *)&LAB_40172ac6_2)(0,0x40240000,(int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
  uVar3 = (*(code *)&SUB_4000c944)(*(undefined1 *)(param_1 + 0x3c));
  (*(code *)&SUB_40002954)
            ((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),(int)uVar3,(int)((ulonglong)uVar3 >> 0x20));
  uVar1 = (*(code *)&SUB_40002b90)();
  uVar1 = FUN_40187018((float)param_2 / 1.0,uVar1);
  return uVar1;
}

